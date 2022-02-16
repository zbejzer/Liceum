#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <utility>

using namespace std;

int main()
{
    unordered_map<string, float> companies;
    map<string, float> prices;
    string current_read;
    pair<string, float> max;

    ifstream price_file("cennik.txt");
    ifstream data_file("cukier.txt");

    while( price_file >> current_read )
    {
        float value;

        price_file >> value;

        prices.emplace(current_read, value);
    }

    while( data_file >> current_read )
    {
        string nip;
        int amount;

        data_file >> nip >> amount;

        companies[nip] += prices.at(current_read.substr(0, 4)) * amount;
    }

    for( auto i : companies )
    {   
        if( i.second > max.second )
            max = i;
    }

    cout << max.first << endl;

    return 0;
}