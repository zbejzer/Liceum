#include <iostream>

using namespace std;

int main(){
    int a, b;
    char c;

    cout << "Podaj a i b: ";
    cin >> a >> b;

    cout << "\nWybierz dzialanie: \n";
    cout << "+ - dodawanie \n";
    cout << "- - odejmowanie \n";
    cout << "* - mnozenie \n";
    cout << "/ - dzielenie \n";
    cout << "% - reszta z dzielenia \n";
    cin >> c;

    switch(c){
        case '+':
            cout << a + b << endl;
            break;
        case '-':
            cout << a - b << endl;
            break;
        case '*':
            cout << a * b << endl;
            break;
        case '/':
            cout << a / (float)b << endl;
            break;
        case '%':
            cout << a % b << endl;
            break;
        default:
            cout << "Niepoprawna operacja! \n";
    }

    getchar();
    getchar();
    
    return 0;
}