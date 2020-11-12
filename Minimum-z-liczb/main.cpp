#include <iostream>
#include <limits.h>

using namespace std;

int main(){
    int n, liczba = 1, minimum = INT_MAX, maximum = INT_MIN;

    cout << "Podaj n: ";
    cin >> n;

    for(int i=0; i<n; i++){
        cout << "Podaj liczbe: ";
        cin >> liczba;

        if(liczba < minimum)
            minimum = liczba;

        if(liczba > maximum)
            maximum = liczba;
    }

    cout << "Namjniejsza liczba: " << minimum << endl;
    cout << "Najwieksza liczba: " << maximum;

    getchar();
    getchar();

    return 0;
}