#include <iostream>
#include <vector>

using namespace std;

int horner(vector <int> wsp, int x)
{
	int wynik = wsp[0];

	for(int i=1; i<wsp.size(); i++)
		wynik = wynik*x + wsp[i];
	
	return wynik;
}

int main()
{
	int stopien, argument;
	
	cout << "Podaj stopień wielomianu: ";
	cin >> stopien;
	vector <int> wsp(stopien+1);
	
	//wczytanie współczynników
	for(int i=0;i<=stopien;i++)
	{
		cout << "Podaj współczynnik a" << stopien-i << ": ";
		cin >> wsp[i];
	}
	
	cout << "Podaj argument: ";
	cin >> argument;
	
	cout << "W(" << argument << ") = " << horner(wsp, argument) << endl;
	
	cin.ignore();
	getchar();
	return 0;
}