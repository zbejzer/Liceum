#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int NWD(int x, int y)
{
    while (x!=y)
    {
        if(x>y)
            x-=y;
        else
            y-=x;
    }
    return x;
}

int main()
{
    ifstream wejscie("liczby.txt");

    int liczby[500];
    int obecnyNWD;
    int obecnaDlugosc = 0;
    int k=2;
    int najdluzszy = 0, pierwszaLiczba, vNWD;

    for(int i=0; i<500; i++)
        wejscie >> liczby[i];

    
    obecnyNWD = NWD(liczby[0], liczby[1]);

    for(int i=2; i<500; i++)
    {
        if(NWD(obecnyNWD, liczby[i]) > 1)
        {
            obecnyNWD = NWD(obecnyNWD, liczby[i]);
            obecnaDlugosc++;
        }
        else
        {
            if(obecnaDlugosc > najdluzszy)
            {
                najdluzszy = obecnaDlugosc;
                pierwszaLiczba = liczby[i-obecnaDlugosc];
                vNWD = obecnyNWD;
            }

            obecnaDlugosc = 1;
            obecnyNWD = liczby[i];
        }
    }

    cout << pierwszaLiczba << " " << najdluzszy << " " << vNWD;

    return 0;
}