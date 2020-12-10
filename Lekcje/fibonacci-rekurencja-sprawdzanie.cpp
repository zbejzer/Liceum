#include <iostream>
#include <limits.h>

using namespace std;

int fibonacci(int a){
    if(a<2)
        return 1;

    return fibonacci(a-1) + fibonacci(a-2);   
}

bool czy_fibonacci(int a){
    bool jest_fibonacci = false;

    for(int i=1; i<=a; i++)
        if( fibonacci(i) == a ){
            jest_fibonacci = true;
            break;
        }

    return jest_fibonacci;
}

int main(){
    int liczba;   

    do
    {
        cout << "Podaj liczbe z przedziału od 1 do 100: ";
        cin >> liczba;

        if( liczba<1 || liczba>100 )
            cout << "Niepoprawna liczba!\n";
        else
            if( czy_fibonacci(liczba) )
                cout << "Liczba jest w ciągu fibonacciego!\n";
            else
                cout << "Liczba nie jest w ciągu fibonacciego!\n";
    }while( liczba<1 || liczba>100 );

    getchar();
    getchar();

    return 0;
}