#include <iostream>

using namespace std;

int tab[10];

void wczytanie() {
	for(int i=0; i<10; i++) {
		cout<<"Podaj "<<i+1<<" liczbe: ";
		cin>>tab[i];
	}
}

void wypisanie() {
	for(int i=0; i<10; i++) {
		cout<<i+1<<" liczba to: "<<tab[i]<<endl;
	}
}

int main() {
	wczytanie();
	wypisanie();
	
	cin.sync();
	getchar();
	
	return 0;
}
