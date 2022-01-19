#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ifstream input_data("pary.txt");

    for(int i=0; i<100; i++)
    {
        string curr_text, longest_text, curr_seq;
        int dummy, longest_length = 1, curr_len;

        input_data >> dummy >> curr_text;
        
        curr_seq = curr_text.at(0);
        longest_text = curr_seq;
        curr_len = 1;

        for(int i=1; i<curr_text.size(); i++)
        {
            if( curr_text.at(i) == curr_text.at(i-1) )
            {
                curr_len++;
                curr_seq += curr_text.at(i);

                if(curr_len > longest_length)
                {
                    longest_length = curr_len;
                    longest_text = curr_seq;
                }
            }
            else {
                curr_len = 1;
                curr_seq = curr_text.at(i);
            }
        }

        cout << longest_text << " " << longest_length << endl;
    }

    return 0;
}