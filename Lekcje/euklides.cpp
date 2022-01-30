#include <iostream>
#include <math.h>

using namespace std;

int nwd_dzielenie(int a, int b){
    while(a > 0)
    {
        a %= b;
        b -= a;
    }

    return b;
}

int nwd_odejmowanie(int a, int b){

    while(a != b){
        if(a > b){
            a-=b;
        }else{
            b-=a;
        }
    }
    
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