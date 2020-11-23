#include <iostream>

using namespace std;

int main(){
    int a, b;

    cout << "Podaj a i b: ";
    cin  >> a >> b;

    while(b!=0){
        cout << "iloraz: " << (float)a/b << endl;
        cout << "Podaj a i b: ";
        cin  >> a >> b;
    }

    getchar();
    getchar();

    return 0;
}