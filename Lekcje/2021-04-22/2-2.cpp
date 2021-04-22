#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

int silnia(int liczba)
{
    int wynik = 1;

    for(int i=2; i<=liczba; i++)
    {
        wynik *= i;
    }

    return wynik;
}

int sumaSilni(string liczba)
{
    int suma = 0;

    for(int i=0; i<liczba.size(); i++)
    {
        suma += silnia(stoi( liczba.substr(i, 1) ));
    }

    return suma;
}

int main()
{
    ifstream wejscie("liczby.txt");

    for(int i=0; i<500; i++)
    {
        int cNumber;

        wejscie >> cNumber;

        if(sumaSilni(to_string(cNumber)) == cNumber) cout << cNumber << ", ";
    }

    return 0;
}