#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int suma;
    string wejscie;

    cin >> wejscie;
    
    suma = count(wejscie.begin(), wejscie.end(), 'a');

    cout << suma;

    getchar();
    getchar();
    return 0;
}