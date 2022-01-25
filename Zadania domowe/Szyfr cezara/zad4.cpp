#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string szyfrCezara( string wejscie, int klucz )
{
    string wyjscie = "";

    for(int i = 0; i < wejscie.size(); i++)
    {
        int nowy_kod = wejscie.at(i) + klucz;

        if( nowy_kod > 'Z' )
            wyjscie += nowy_kod + 'A' - 'Z' - 1;
        else
            wyjscie += nowy_kod;
    }

    return wyjscie;
}

int main()
{
    ifstream input_data("dane_zadanie_4.txt");

    for(int i=0; i<100; i++)
    {
        string new_word;

        input_data >> new_word;

        cout << szyfrCezara( new_word, new_word.size() ) << endl;
    }

    return 0;
}