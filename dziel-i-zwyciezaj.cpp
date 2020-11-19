#include <iostream>
#include <limits.h>
#include <utility>
#include <vector>
#include <array>

using namespace std;

pair <vector <int>, vector <int>> divide_conquer(vector <int> liczby)
{
    vector <int> tablica_a(liczby.size()/2);    //wieksze
    vector <int> tablica_b(liczby.size()/2);    //mniejsze
    pair <vector <int>, vector <int>> wyniki;

    for(int i=0; i<liczby.size(); i=i+2) {
        if(liczby[i]>liczby[i+1]){
            tablica_a[i/2] = liczby[i];
            tablica_b[i/2] = liczby[i+1];
        }else{
            tablica_a[i/2] = liczby[i+1];
            tablica_b[i/2] = liczby[i];
        }
    }

    if(liczby.size()%2 != 0){
        tablica_a.push_back( liczby[liczby.size() - 1] );
        tablica_b.push_back( liczby[liczby.size() - 1] );
    }

    wyniki.first = tablica_a;
    wyniki.second = tablica_b;

    return wyniki;
}

int max_liczba(vector <int> liczby){
    int wynik = INT_MIN;

    for(int i=0; i<liczby.size(); i++){
        if(liczby[i] > wynik)
            wynik = liczby[i];
    }

    return wynik;
}

int min_liczba(vector <int> liczby){
    int wynik = INT_MAX;

    for(int i=0; i<liczby.size(); i++){
        if(liczby[i] < wynik)
            wynik = liczby[i];
    }

    return wynik;
}

int main(){
    int n;
    vector <int> liczby;

    cout << "Podaj n: ";
    cin >> n;

    for(int i=0; i<n; i++){
        int liczba;
        cout << "Podaj liczbe: ";
        cin >> liczba;
        liczby.push_back(liczba);
    }

    pair <vector <int>, vector <int>> podzielony;

    podzielony = divide_conquer(liczby);

    cout << "max: " << max_liczba(podzielony.first) << endl;
    cout << "min: " << min_liczba(podzielony.second) << endl;

    getchar();
    getchar();

    return 0;
}