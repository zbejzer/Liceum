#include <iostream>
#include <limits.h>

using namespace std;

int main() {
    int a = 1, suma = 0;

    for(int i=1; a>0; i++){
        cout << "Podaj liczbe: ";
        cin >> a;

        if(a > 0)
        {
            suma += a;
            cout << "Srednia: " << float(suma)/i << "\n";
        } else {
            cout << "Koniec! \n";
        }
    }

	cin.ignore(INT_MAX, '\n');
	getchar();
	return 0;
}
