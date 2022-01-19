#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int main() {
    int a = 1, suma = 0;
    vector <int> par;
    vector <int> npar;

    while( a!=0 ){
        cout << "Podaj liczbe: ";
        cin >> a;

        if(a%2)
            npar.push_back(a);
        else
            par.push_back(a);

        cout << "Nie parzyste: ";
        for(int i=0; i<npar.size(); i++)
            cout << npar[i] << ", ";

        cout << "\n";
        cout << "Parzyste: ";
        for(int i=0; i<par.size(); i++)
            cout << par[i] << ", ";
        cout << "\n\n";
    }

    cout << "\n";
	cin.ignore(INT_MAX, '\n');
	getchar();
	return 0;
}
