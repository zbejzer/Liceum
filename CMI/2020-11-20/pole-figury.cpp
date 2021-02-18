#include <iostream>

using namespace std;

int main(){
    char c;
    double a, b, h;

    cout << "\nWybierz rzecz do obliczenia: \n";
    cout << "a - pole kwadratu \n";
    cout << "b - pole prostokata \n";
    cout << "c - pole trojkata \n";
    cout << "d - pole trapezu \n";
    cin >> c;

    switch(c){
        case 'a':
            cout << "Podaj a: ";
            cin >> a;
            cout << a*a << endl;
            break;
        case 'b':
            cout << "Podaj a i b: ";
            cin >> a >> b;
            cout << a*b << endl;
            break;
        case 'c':
            cout << "Podaj a i h: ";
            cin >> a >> h;
            cout << a*h/2 << endl;
            break;
        case 'd':
            cout << "Podaj a, b, h: ";
            cin >> a >> b >> h;
            cout << (a+b)*h/2 << endl;
            break;
        default:
            cout << "Niepoprawna operacja! \n";
    }

    getchar();
    getchar();
    
    return 0;
}