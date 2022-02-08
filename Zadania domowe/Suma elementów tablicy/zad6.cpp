#include <iostream>
#include <fstream>
#include <array>

#define DATA_SIZE 100000 // 8

using namespace std;

int main()
{
    ifstream data_input("dane1_4.txt"); // test

    array<int, DATA_SIZE> data;
    int maximal_sum, current_sum = 0, max_start = 0, max_end = 0, current_start = 0;

    for(int i=0; i<data.size(); i++)
        data_input >> data.at(i);

    maximal_sum = data.at(0);

    for(int i=0; i<data.size(); i++)
    {   
        current_sum += data.at(i);

        if( current_sum > maximal_sum )
        {
            maximal_sum = current_sum;
            max_start = current_start;
            max_end = i;
        }

        if( current_sum <= 0 )
        {
            current_sum = 0;
            current_start = i+i;
        }
            
    }

    cout << max_start + 1 << " " << max_end + 1 << endl;

    return 0;
}