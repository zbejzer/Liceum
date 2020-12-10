#include <iostream>
#include <limits.h>

using namespace std;

__UINT64_TYPE__ silnia(int liczba){
    if(liczba > 0)
        return liczba*silnia(liczba-1);
    else 
        return 1;    
}

double newton(int n, int k){
    double wynik = silnia(n)/(silnia(k)*silnia(n-k));
    return wynik;
}

int main(){
    int k, S;

    cout << "Podaj ilosc osob w reprezentacji: ";
    cin >> k;
    cout << "Podaj ilosc osob w szkole: ";
    cin >> S;
    cout << "Mozna wybrac na: " << newton(S, k) << " sposobow.\n";

    cin.ignore(INT_MAX, '\n');
    getchar();

    return 0;
}
