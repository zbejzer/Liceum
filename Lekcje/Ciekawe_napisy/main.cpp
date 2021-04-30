#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool isPrime(int liczba)
{
    int end = (liczba/2)+1;

    for(int i=2; i<=end; i++)
    {
        if(liczba%i == 0)
            return false;
    }
    return true;
}

int main()
{
    ifstream wejscie("NAPIS.txt");
    int primeCounter = 0;
    vector<string> rosnace;
    map<string,int> powtorzenia;

    for(int i=0; i<1000; i++)
    {
        string wyraz;
        int sumaASCII = 0;
        bool jestRosnace = true;
        wejscie >> wyraz;

        for(int k=0; k<wyraz.size(); k++)
            sumaASCII += wyraz[k];

        for(int k=1; k<wyraz.size(); k++)
        {
            if( wyraz[k-1] >= wyraz[k] )
                jestRosnace = false;
        }

        powtorzenia[wyraz]++;

        if(isPrime(sumaASCII))
            primeCounter++;

        if(jestRosnace)
            rosnace.push_back(wyraz);
    }

    cout << primeCounter << endl;

    for(int i=0; i<rosnace.size(); i++)
        cout << rosnace[i] << " ";
    cout << endl;

    for(auto k : powtorzenia)
    {
        if(k.second > 1)
            cout << k.first << " ";
    }
        

    return 0;
}