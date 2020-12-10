#include <iostream>
#include <limits.h>

using namespace std;

int fibonacci(int a){
    if(a<2)
        return 1;

    return fibonacci(a-1) + fibonacci(a-2);   
}

int main(){
    int poczatek, koniec;   

    cout << "Podaj poczatek i koniec zakresu: ";
    cin >> poczatek >> koniec;

    cout << "Liczby fibonacciego z zakresu: ";
    for(int i=0; fibonacci(i)<=koniec; i++)
        if( fibonacci(i)>=poczatek )
            cout << fibonacci(i) << " ";

    cin.ignore(INT_MAX, '\n');
    getchar();
    return 0;
}