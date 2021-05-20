#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int roznica(vector <int> liczby){
    int max = liczby[0];
    int min = liczby[0];

    for(int i=0; i<liczby.size(); i++){
        if(liczby[i] > max)
            max = liczby[i];

        if(liczby[i] < min)
            min = liczby[i];
    }

    return max-min;
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
    
    cout << "Roznica liczba to: " << roznica(liczby);   

	cin.ignore(INT_MAX, '\n');
	getchar();
	return 0;
}
