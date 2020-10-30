#include <iostream>
#include <limits.h>

using namespace std;

int main(){
    int wejscie, suma;

    for(int i = 0; i < 10; i++){
        cin >> wejscie;
        suma += wejscie;
    }

    cout << suma/10;

    cin.ignore(INT_MAX, 10);
    getchar();
    return 0;
}