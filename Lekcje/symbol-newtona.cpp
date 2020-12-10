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
    int n, k;

    cout << "Podaj n i k: ";
    cin >> n >> k;
    cout << newton(n, k);

    cin.ignore(INT_MAX, '\n');
    getchar();

    return 0;
}
