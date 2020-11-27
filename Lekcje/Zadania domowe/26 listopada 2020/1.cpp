#include <iostream>
#include <limits.h>

using namespace std;

int main() {
    int n, counter = 0;

	cout << "Podaj ilosc liczb: ";
    cin >> n;

    for(int i=0; i<n; i++)
    {
        int a;

        cout << "Podaj liczbe " << i+1 << ": ";
        cin >> a;
        
        if(a%2 > 0)
            counter++;
    }

    cout << "Liczb nieparzystych: " << counter << endl;

	cin.ignore(INT_MAX, '\n');
	getchar();
	return 0;
}
