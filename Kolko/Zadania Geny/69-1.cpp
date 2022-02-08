#include <iostream>
#include <fstream>
#include <string>
#include <map>

#define DATA_SIZE 1000

using namespace std;

int main()
{
    ifstream input_data("dane_geny.txt");

    map<int, int> generes;
    map<int, int>::iterator it;
    int most_common_genere = 0;

    for( int i=0; i<DATA_SIZE; i++ )
    {
        string current_gentype;
        input_data >> current_gentype;

        // cout << current_gentype.size() << endl;

        generes[current_gentype.size()]++;
    }

    cout << generes.size() << endl;

    for( it=generes.begin(); it!=generes.end(); it++ )
    {
        if( it->second > most_common_genere )
            most_common_genere = it->second;
    }

    cout << most_common_genere << endl;

    return 0;
}