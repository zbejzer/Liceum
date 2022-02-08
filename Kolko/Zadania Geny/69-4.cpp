#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

#define DATA_SIZE 1000 // 1000

using namespace std;

bool isPalindrome( string a )
{
    string reversed_a = "";

    for(int i = 0; i < a.size(); i++)
        reversed_a += a.at( a.size() - i - 1);

    return reversed_a == a;
}

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

    int resistant_genome = 0, highly_resistant_genome = 0;

    for( int i=0; i<DATA_SIZE; i++ )
    {
        string current_genome;
        string reversed_genome = "";

        input_data >> current_genome;

        if( isPalindrome( current_genome ) )
            highly_resistant_genome++;

        for( int j=0; j<current_genome.size(); j++ )
            reversed_genome += current_genome.at( current_genome.size() - j - 1);

        if( extractGenes(current_genome) == extractGenes(reversed_genome) )
            resistant_genome++;
    }

    cout << resistant_genome << endl;
    cout << highly_resistant_genome << endl;

    return 0;
}