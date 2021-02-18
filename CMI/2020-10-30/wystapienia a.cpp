#include <iostream>
#include <string.h>
#include <limits.h>
#include <algorithm>

using namespace std;

int main(){
    int suma=0;
    char imie[CHAR_MAX];

    cout << "Podaj imie: ";
    cin >> imie;
    
    for(int i=0; i<strlen(imie); i++)
        if(imie[i]=='a' || imie[i]=='A')
            suma++;

    cout << suma;

    getchar();
    getchar();
    return 0;
}