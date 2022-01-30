#include <iostream>

using namespace std;

int nwd_dzielenie(int a, int b){
    if(a > 0)
        return nwd_dzielenie(a%b, b-(a%b));
    else
        return b;
}

int nwd_odejmowanie(int a, int b){
    if(a != b)
    {
        if(a > b)
            return nwd_odejmowanie(a-b, b);
        else
            return nwd_odejmowanie(a, b-a);
    } else
        return a;
}

int main(){
    int a, b;

    cout << "Podaj a i b do obliczenia NWD: ";
    cin >> a >> b;

    cout << "Odejmowanie: " << nwd_odejmowanie(a, b) << endl;
    cout << "Dzielenie: " << nwd_dzielenie(a, b) << endl;

    return 0;
}