#include <iostream>
#include <limits.h>

using namespace std;

int MaxN(int num[], int n)
{
    int max = num[0];
    for(int i=0; i<n; i++)
    {
        if(num[i] > max)
            max = num[i];
    }

    return  max;
}

int main() {
    int n;

    cout << "Podaj ilosc liczb: ";
    cin >> n;

    int num[n];

    for(int i=0; i<n; i++)
    {
        cout << "Podaj " << i+1 << " liczbe: ";
        cin >> num[i]; 
    }
    
    cout << "Najwieksza liczba to: " << MaxN(num, n);   

	cin.ignore(INT_MAX, '\n');
	getchar();
	return 0;
}
