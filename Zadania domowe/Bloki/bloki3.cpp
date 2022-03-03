#include <iostream>
#include <fstream>
#include <vector>

#define DATA_SIZE 1000000
#define FILE_NAME "bloki3.txt"

using namespace std;

int main()
{
    ifstream bloki1(FILE_NAME);
    vector<int> numbers(DATA_SIZE);
    int max_lenght = 0;

    for(int i=0; i<DATA_SIZE; i++)
    {
        int current_number;
        bloki1 >> current_number;
        
        //cout << current_number << endl;

        if(i > 0)
        {
            numbers.at(i) = (numbers.at(i - 1) + current_number) % 3;
        } else {
            numbers.at(i) = current_number % 3;
        }

        //cout << numbers.at(i) << endl;
    }

    for( int n = 0; n<3; n++ )
    {   
        int lhs, rhs;

        for( int i = 0; i < numbers.size(); i++ )
        {
            if( numbers.at(numbers.size() - 1 - i) == n )
            {
                lhs = numbers.size() - 1 - i;
            }

            //cout << numbers.size() - 1 - i << endl;
        }

        //cout << lhs << endl;

        rhs = lhs;

        for( int i = lhs; i < numbers.size(); i++ )
        {
            if( numbers.at(i) == n )
            {
                rhs = i;
            }
        }

        if( rhs - lhs > max_lenght )
        {
            max_lenght = rhs - lhs;
        }
    }

    cout << max_lenght << endl;

    return 0;
}