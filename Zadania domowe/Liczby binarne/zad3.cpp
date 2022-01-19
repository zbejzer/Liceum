#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

bool isBinaryBigger(string a, string b)
{
    if( a.size() == b.size() )
    {
        for(int i=0; i<a.size(); i++)
        {
            if( a.at( a.size() - 1 - i) > b.at( b.size() - 1 - i) )
                return true;
            else
                return false;
        }
    }
    else if( a.size() > b.size() )
        return true;
    
    return false;
}

int main()
{
    ifstream input_data("liczby.txt");

    string max_number = "";

    for(int i=0; i<1000; i++)
    {
        string new_row;
        unordered_map<char, int> digit_count;

        digit_count['0'] = 0;
        digit_count['1'] = 0;

        input_data >> new_row;

        for(int j=0; j<new_row.size(); j++)
        {
            digit_count[ new_row.at(j) ]++;
        }
        
        if( ( new_row.at( new_row.size() - 1 ) == '0' ) && ( digit_count['1'] > digit_count['0'] ) && isBinaryBigger(new_row, max_number) )
            max_number = new_row;
    }

    cout << max_number;

    return 0;
}