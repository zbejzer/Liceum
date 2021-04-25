#include <fstream>
#include <cmath>
#include <string>

using namespace std;

int binDec(string binary)
{
    int wynik = 0;

    for(int i=1; i<=binary.size(); i++)
        wynik += pow(2, i-1) * (binary[binary.size()-i]-'0');

    return wynik;
}

string decBin(int wejscie){
    string wyjscie = "";

    do {
        int reszta = wejscie%2;
        wejscie /= 2;

        wyjscie = to_string(reszta) + wyjscie;
    } while (wejscie > 0);

    return wyjscie;
}

int main()
{
    string binarne[1000];
    int decymalne[1000];
    int nParzystych = 0, iMax = 0, nDziewiec = 0, sumaDziewiec = 0;
    ifstream wejscie("liczby.txt");
    ofstream wyjscie("zadanie6.txt");

    for(int i=0; i<1000; i++)
    {
        wejscie >> binarne[i];
        decymalne[i] = binDec(binarne[i]);

        if(binarne[i][ binarne[i].size()-1 ] == '0')
            nParzystych++;
    }

    for(int i=0; i<1000; i++)
    {
        if(decymalne[i] > decymalne[iMax])
            iMax = i;

        if(binarne[i].size() == 9)
        {
            nDziewiec++;
            sumaDziewiec += decymalne[i];
        }
    }

    wyjscie << "a)" << nParzystych << endl;
    wyjscie << "b)" << binarne[iMax] << "\t" << decymalne[iMax] << endl;
    wyjscie << "c)" << nDziewiec << "\t" << decBin(sumaDziewiec) << endl;

    return 0;
}