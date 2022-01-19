#include <iostream>
#include <math.h>
#include <limits.h>
#include <string>

using namespace std;

string sumaCyfr(string a, string b){
    int suma_a = 0, suma_b = 0;

    for(int i=0; i<a.size(); i++)
        suma_a += stoi(string(1, a[i]));

    for(int i=0; i<b.size(); i++)
        suma_b += stoi(string(1, b[i]));

    if(suma_a > suma_b)
        return a;
    else
        return b;
}

int main(){
    string a, b;

    do{
        cout << "Podaj liczbe a: ";
        cin >> a;
    }while(stoi(a) <= 1);

    do{
        cout << "Podaj liczbe b: ";
        cin >> b;
    }while(stoi(b) <= 1);

    cout << "Liczba o wiekszej sumie cyfr: " << sumaCyfr(a,b);
  
	cin.ignore(INT_MAX, '\n');
	getchar();
	return 0;
}