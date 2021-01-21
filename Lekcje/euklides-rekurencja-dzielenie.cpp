#include <iostream>
#include <limits.h>

using namespace std;

int nwd_dzielenie(int a, int b){
    if(a > 0)
        return nwd_dzielenie(a%b, b-(a%b));
    else
        return b;
}

int main(){
    int a, b;

    cout << "Podaj a i b do obliczenia NWD: ";
    cin >> a >> b;

    cout << "NWD z " << a << " i " << b << ": ";
    cout << nwd_dzielenie(a, b) << endl;

    cin.ignore(INT_MAX, '\n');
    getchar();

    return 0;
}