#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ifstream input_data("instrukcje.txt");
   
    int max_seq_len = 0, curr_seq_len = 0;
    string max_seq_instruct = "", last_instruct = "";

    for(int i=0; i<2000; i++)
    {
        string dump, curr_instruct;

        input_data >> curr_instruct >> dump;

        if( curr_instruct == last_instruct )
        {
            curr_seq_len++;

            if(curr_seq_len > max_seq_len)
            {
                max_seq_len = curr_seq_len;
                max_seq_instruct = curr_instruct;
            }
        }
        else {
            last_instruct = curr_instruct;
            curr_seq_len = 1;
        }
    }

    cout << max_seq_instruct << " " << max_seq_len << endl;

    return 0;
}