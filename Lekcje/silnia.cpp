#include <iostream>

using namespace std;

unsigned long long int silnia(int liczba){
    unsigned long long int wynik=1;

    for(int i=2; i<=liczba; i++)
        wynik*=i;

    return wynik;
}

int main(){
    int liczba;

    cout << "Podaj liczbe do obliczenia silni: ";
    cin >> liczba;

    cout << "Wartosc silni z " << liczba << ": " << silnia(liczba) << endl;

    getchar();
    getchar();

    return 0;
}