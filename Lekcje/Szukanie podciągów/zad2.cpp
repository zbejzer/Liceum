#include <fstream>
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    ifstream input_data("dane4.txt");
    int last_number, last_diff, longest_seq_len = 0, longest_seq_start, longest_seq_end, curr_number, curr_seq_len = 2, curr_seq_start;

    input_data >> last_number >> curr_number;

    curr_seq_start = last_number;
    last_diff = abs(last_number - curr_number);
    last_number = curr_number;

    for(int i=2; i<1000; i++)
    {
        input_data >> curr_number;

        if( abs(last_number - curr_number) == last_diff )
        {
            curr_seq_len++;

            if(curr_seq_len > longest_seq_len)
            {
                longest_seq_len = curr_seq_len;
                longest_seq_start = curr_seq_start;
                longest_seq_end = curr_number;
            }
        }
        else {
            last_diff = abs(last_number - curr_number);
            curr_seq_len = 2;
            curr_seq_start = last_number;
        }

        last_number = curr_number;
    }

    cout << longest_seq_len << " " << longest_seq_start << " " << longest_seq_end << endl;

    return 0;
}