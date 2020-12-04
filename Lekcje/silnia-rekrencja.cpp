#include <iostream>

using namespace std;

__uint128_t silnia(int liczba){
    if(liczba > 0)
        return liczba*silnia(liczba-1);
    else 
        return 1;    
}

int main(){
    int liczba;

    cout << "Podaj liczbe do obliczenia silni: ";
    cin >> liczba;
    for(int i=0; i<=liczba; i++)
        cout << "Wartosc silni z " << i << ": " << silnia(i) << endl;

    getchar();
    getchar();

    return 0;
}
