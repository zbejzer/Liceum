#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main() {
    string liczba;
    int liczba_dec = 0;
    cin >> liczba;
    cin.ignore();

    for(int i=0; i < liczba.size(); i++) {
        if(liczba[liczba.size() - i - 1] == '1') {
            liczba_dec += pow( 2, i );
        }
    }

    cout << liczba_dec;

    getchar();
    return 0;
}