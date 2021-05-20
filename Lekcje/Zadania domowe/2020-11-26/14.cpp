#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

float srednia(vector <int> liczby){
    int suma = 0;

    for(int i=0; i<liczby.size(); i++)
        suma += liczby[i];

    return suma/liczby.size();
}

int najblizszy(vector <int> liczby){
    int x = liczby[0];
    float avg = srednia(liczby);

    for(int i=0; i<liczby.size(); i++)
        if( abs(avg - liczby[i]) < abs(avg - x) )
            x = liczby[i];

    return x;
}

int main() {
    int n;
    vector <int> liczby;

    cout << "Podaj ilosc liczb: ";
    cin >> n;

    for(int i=0; i<n; i++)
    {
        int a;
        cout << "Podaj " << i+1 << " liczbe: ";
        cin >> a; 
        liczby.push_back(a); 
    }
    
    cout << "Najblizsza sredniej liczba to: " << najblizszy(liczby);   

	cin.ignore(INT_MAX, '\n');
	getchar();
	return 0;
}
