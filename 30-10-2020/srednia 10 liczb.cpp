#include <iostream>
#include <limits.h>
#include <iomanip>

using namespace std;

int main(){
    int wejscie, suma=0;

    for(int i = 0; i < 10; i++){
        cin >> wejscie;
        suma += wejscie;
    }

    cout << fixed << setprecision(2) << suma/10.0;

    cin.ignore(INT_MAX, 10);
    getchar();
    return 0;
}