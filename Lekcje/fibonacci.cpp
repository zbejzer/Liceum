#include <iostream>

using namespace std;

fibonacci(int n){
    int liczby[3] = {1, 0, 1};

    for(int i=1; i<=n; i++){
        liczby[0] = liczby[1] + liczby[2];
        cout << liczby[0] << endl;
        liczby[2] = liczby[1];
        liczby[1] = liczby[0];
    }
}

n_fibonacci(int n){
    int liczby[3] = {1, 0, 1};

    for(int i=1; i<=n; i++){
        liczby[0] = liczby[1] + liczby[2];
        liczby[2] = liczby[1];
        liczby[1] = liczby[0];
    }

    cout << liczby[1] << endl;
}

int main(){
    int n, c;

    cout << "[0] Podaj ilosc liczb ciagu Fibonacciego do wygenerowania" << endl;
    cout << "[1] Podaj n-liczbe ciagu Fibonacciego do wygenerowania" << endl;
    cin >> c;
    cout << "Podaj n: ";
    cin >> n;

    switch (c){
    case 0:
        fibonacci(n);
        break;

    case 1:
        n_fibonacci(n);
        break;
    
    default:
        break;
    }

    getchar();
    getchar();

    return 0;
}