#include <iostream>

using namespace std;

int fibonacci(int a){
    if(a<2)
        return 1;

    return fibonacci(a-1) + fibonacci(a-2);   
}

int main(){
    int n, c;
    bool wybrano = false;

    while(!wybrano)
    {   cout << "Wybierz polecenie:\n";
        cout << "[0] Podaj ilosc liczb ciagu Fibonacciego do wygenerowania\n";
        cout << "[1] Podaj n-liczbe ciagu Fibonacciego do wygenerowania" << endl;
        cin >> c;
        cout << "Podaj n: ";
        cin >> n;

        switch (c){
        case 0:
            for(int i=0; i<n; i++)
                cout << fibonacci(i) << "\n";
            wybrano = true;
            break;

        case 1:
            cout << fibonacci(n-1) << "\n";
            wybrano = true;
            break;
        
        default:
            cout << "Niepoprawny wybor.\n";
            break;
        }
    }

    getchar();
    getchar();

    return 0;
}