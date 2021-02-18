#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string cezar(string wyraz, int krok)
{
    for(int i=0; i<wyraz.size(); i++){
        if(wyraz[i] + krok > 'Z')
            wyraz[i] = wyraz[i] + krok - ('Z' - 'A');
        else
            wyraz[i] = wyraz[i] + krok;
    }

    return wyraz;
}

int main(){
    ifstream f_wejscie("dane_6_1.txt");
    ofstream f_wyjscie("6_1.txt");

    int krok;
    string dane[100];

    cout << "Podaj krok: ";
    cin >> krok;

    for(int i=0; i<100; i++)
        f_wejscie >> dane[i];

    for(int i=0; i<100; i++)
    {
        cout << "Wczytane dane: " << dane[i] << endl;
        cout << "Szyfr Cezara: " << cezar(dane[i], 3) << endl;
        cout << "========================" << endl;
        f_wyjscie << cezar(dane[i], krok) << endl;
    }

    f_wejscie.close();
    f_wyjscie.close();
    getchar();
    getchar();
    return 0;
}