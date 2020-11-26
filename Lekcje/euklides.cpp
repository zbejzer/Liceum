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
    int a, b, wybor;

    cout << "Podaj a i b do obliczenia NWD: ";
    cin >> a >> b;

    cout << "Podaj sposob obliczania: " << endl;
    cout << "[0] odejmowanie" << endl;
    cout << "[1] dzielenie" << endl;
    cin >> wybor;
    cout << "NWD z " << a << " i " << b << ": ";

    switch (wybor)
    {
    case 0:
        cout << nwd_odejmowanie(a,b) << endl;
        break;
    
    case 1:
        cout << nwd_dzielenie(a,b) << endl;
        break;
    }

    getchar();
    getchar();

    return 0;
}