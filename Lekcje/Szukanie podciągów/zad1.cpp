#include <fstream>
#include <iostream>
#include <array>

using namespace std;

int NWD(int a, int b)
{
    int max_div = 1;

    for(int i=2; i<=max(a, b); i++)
    {
        if( ( a%i == 0 ) && ( b%i == 0 ) )  max_div = i;
    }

    return max_div;
}

int main()
{
    ifstream input_data("liczby.txt");

    int last_number, last_div, max_seq_div, max_seq_len = 0, curr_number, curr_seq_len = 2, max_seq_start, curr_seq_start;

    input_data >> last_number >> curr_number;

    curr_seq_start = last_number;
    last_div = NWD(last_number, curr_number);
    last_number = curr_number;

    for(int i=2; i<500; i++)
    {
        input_data >> curr_number;

        int curr_div = NWD(last_div, curr_number);

        if( curr_div > 1 )
        {
            curr_seq_len++;
            last_div = curr_div;

            if(curr_seq_len > max_seq_len)
            {
                max_seq_len = curr_seq_len;
                max_seq_start = curr_seq_start;
                max_seq_div = curr_div;
            }
        }
        else {
            last_div = NWD(last_number, curr_number);
            curr_seq_len = 2;
            curr_seq_start = last_number;
        }

        last_number = curr_number;
    }

    cout << max_seq_start << " " << max_seq_len << " " << max_seq_div << endl;

    return 0;
}