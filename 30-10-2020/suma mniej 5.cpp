#include <iostream>
#include <limits.h>

using namespace std;

int main(){
    int wejscie, suma;

    for(int i = 0; i < 10; i++){
        cin >> wejscie;
        if(wejscie < 5)
            suma += wejscie;
    }

    cout << suma;

    getchar();
    getchar();
    return 0;
}