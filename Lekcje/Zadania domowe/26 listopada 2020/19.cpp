#include <iostream>
#include <math.h>
#include <limits.h>
#include <string>

using namespace std;

bool jestPierwsza(int a){
    int i = 2;

    if(a>=2){
        while(i<a && a%i!=0)
            i++;

        if(a == i)
            return true;
        else
            return false;
    } else {
        return false;
    }
}

int main(){
    int a;

    cout << "Podaj liczbe: ";
    cin >> a;

    if(jestPierwsza(a))
        cout << "Liczba jest pierwsza\n";
    else
        cout << "Liczba nie jest pierwsza\n";
  
	cin.ignore(INT_MAX, '\n');
	getchar();
	return 0;
}