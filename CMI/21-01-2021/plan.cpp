#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{
    int n, suma = 0;
    
    cin >> n;       // ilosc godzin

    bool godziny[n];

    for(int i=0; i<n; i++)
        cin >> godziny[i];

    for(int i=2; i<n; i++)      // wypelnienei 
        if(godziny[i-2] && godziny[i])
            godziny[i-1] = 1;

    for(int i=0; i<n; i++)
        suma += godziny[i];

    
    cout << suma;
    return 0;
}