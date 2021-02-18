#include <iostream>
#include <fstream>
#include <limits.h>
#include <string>
#include <math.h>

using namespace std;

unsigned long long int pow2(unsigned long long int x){
    if( x==0 )
        return 1;
    else
        return pow2(x-1)*2;
}

unsigned long long int bin_dec(string wejscie){
    unsigned long long int suma=0;

    for(int i=1; i<=wejscie.size(); i++)
        suma += pow2(i-1) * (wejscie[wejscie.size()-i]-'0');

    return suma;
}

string dec_bin(unsigned long long int wejscie){
    string wyjscie = "";

    do {
        unsigned long long int reszta = wejscie%2;
        wejscie /= 2;

        wyjscie = to_string(reszta) + wyjscie;
    } while (wejscie > 0);

    return wyjscie;
}

string dec_oct(unsigned long long int wejscie){
    string wyjscie = "";

    do {
        unsigned long long int reszta = wejscie%8;
        wejscie /= 8;

        wyjscie = to_string(reszta) + wyjscie;
    } while (wejscie > 0);

    return wyjscie;
}

int main(){
    const int n = 1000;

    ifstream fin("liczby.txt");
    ofstream fDecOut("liczby-dec.txt");
    ofstream fBinOut("liczby-bin.txt");

    for(int i=0; i<n; i++)
    {
        string wejscie;
        unsigned long long int wynik;
        string przeliczenieBin, przeliczenieOct;

        fin >> wejscie;
        wynik = bin_dec(wejscie);
        przeliczenieBin = dec_bin(wynik);
        przeliczenieOct = dec_oct(wynik);
        cout << "Wejscie \t\t" << wejscie << endl;
        cout << "Wynik \t\t\t" << wynik << endl;
        cout << "Przeliczenie binarne\t" << przeliczenieBin << endl;
        cout << "Przeliczenie osemkowe\t" << przeliczenieOct << endl << endl;

        fDecOut << wynik << endl;
        fBinOut << przeliczenieBin << endl;
    }

    fin.close();
    fDecOut.close();
    fBinOut.close();
    
    cin.ignore(INT_MAX, '\n');
    getchar();
    return 0;
}