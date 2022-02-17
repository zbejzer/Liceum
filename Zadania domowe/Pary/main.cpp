#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string join_sequences(string a, string b)
{
    string min_sum = a + b;

    for(int i = 0; i <= a.size() - b.size(); i++)
    {
        if(a.substr(i, b.size()) == b)
            return a;
    }

    for(int i = 0; i <= b.size(); i++)
    {
        string b_sub_front = b.substr(0, i) , b_sub_back = b.substr(i, b.size() - i);

        if( a.substr(0, b_sub_back.size()) == b_sub_back )
        {
            string current_sum = b.substr(0, b.size() - b_sub_back.size()) + a;

            if( current_sum.size() < min_sum.size() )
                min_sum = current_sum;
        }

        if( a.substr(a.size() - b_sub_front.size(), b_sub_front.size()) == b_sub_front )
        {
            string current_sum = a.substr(0, a.size() - b_sub_front.size()) + b;

            if( current_sum.size() < min_sum.size() )
                min_sum = current_sum;
        }
    }

    return min_sum;
}

int main()
{
    ifstream data("dane.txt");
    string a, b;

    while(data >> a >> b)
    {
        cout << join_sequences(a, b) << endl;
    }

    return 0;
}