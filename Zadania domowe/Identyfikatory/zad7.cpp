#include <iostream>
#include <fstream>
#include <string>
#include <map>

#define FILE_NAME "identyfikator.txt"

using namespace std;

int main()
{
    ifstream data_file(FILE_NAME);

    multimap<int, string> indentificators;
    string new_identificatior;

    while( data_file >> new_identificatior )
    {
        string key = "";
        key += new_identificatior.at(3);
        key += new_identificatior.at(7);
        key += new_identificatior.at(8);

        indentificators.emplace( stoi(key), new_identificatior );
    }
    
    for( auto it = indentificators.rbegin(); it != indentificators.rend(); ++it )
    {
        cout << it -> second << endl;
    }

    return 0;
}