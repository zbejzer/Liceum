#include <iostream>

using namespace std;

int main(){
    int liczba = 1, licznik = 0;

    while(liczba!=0){
        cout << "Podaj liczbe: ";
        cin >> liczba;

        if(liczba%2 ==0 && liczba!=0)
            licznik++;
    }

    cout << "Ilosc liczb parzystych: " << licznik;

    getchar();
    getchar();

    return 0;
}