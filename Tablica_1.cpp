#include <iostream>

using namespace std;

int n;
int tab[32767];


void wczytanie(int tablica[]) {
	for(int i=0; i<n; i++) {
		cout<<"Podaj "<<i+1<<" liczbe: ";
		cin>>tablica[i];
	}
}

void wypisanie(int tablica[]) {
	for(int i=0; i<n; i++) {
		cout<<i+1<<" liczba to: "<<tablica[i]<<endl;
	}
}

void zamien(int tablica[]) {
	int temp[n];
	for(int i=0; i<n; i++) {
		temp[i] = tablica[n-1-i];
	}
	for(int i=0; i<n; i++) {
		tab[i] = temp[i];
	}
}

int main() {
	cout<<"Podaj n: ";
	cin>>n;
	
	wczytanie(tab);
	wypisanie(tab);
	zamien(tab);
	wypisanie(tab);
	
	cin.sync();
	getchar();
	
	return 0;
}
