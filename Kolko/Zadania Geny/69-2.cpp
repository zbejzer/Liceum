#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

#define DATA_SIZE 1000 // 1000

using namespace std;

vector<string> extractGenes(string genotype)
{
    bool bad_order = false;

    vector<string> extracted_genes;

    while( genotype.find("AA", 0)!=string::npos && genotype.find("BB", 0)!=string::npos && !bad_order )
    {
        int start = genotype.find("AA", 0);
        int end = genotype.find("BB", start);
        int length = end - start;

        if( length < 0 )
        {
            bad_order = true;
        } 
        else {
            extracted_genes.push_back( genotype.substr(start, length+2) );
            //cout << extracted_genes.at( extracted_genes.size() - 1 ) << endl;
            genotype = genotype.substr(end+2, genotype.length() - end+2 - 1);
            //cout << genotype << endl;
        }
    }

    return extracted_genes;
}

int main()
{
    ifstream input_data("dane_geny.txt");

    int mutation_count = 0;

    for( int i=0; i<DATA_SIZE; i++ )
    {
        string current_gentype;
        bool has_mutation = false;

        input_data >> current_gentype;

        vector<string> extracted_genes = extractGenes(current_gentype);
        //cout << endl;

        for( int j=0; j<extracted_genes.size(); j++ )
        {
            if( extracted_genes.at( j ).find( "BCDDC", 0 ) != string::npos )
                has_mutation = true;
        }

        mutation_count += has_mutation;
    }

    cout << mutation_count << endl;

    return 0;
}