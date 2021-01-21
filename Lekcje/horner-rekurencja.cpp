#include <iostream>
#include <limits.h>
#include <vector>
#include <math.h>

using namespace std;

int horner(vector <int> wsp, int n, int x)
{
	if(n == 0)
        return wsp[0];
    else
        return x*horner(wsp, n-1, x)+wsp[n];
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
	
	cout << "Podaj argument dla wielomianu: ";
	cin >> argument;
	
	cout << "W(" << argument << ") = " << horner(wsp, stopien, argument) << endl;
	
	cin.ignore(INT_MAX, '\n');
    getchar();
	return 0;
}