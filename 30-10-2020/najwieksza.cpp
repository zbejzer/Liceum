#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

int main(){
    int wejscie[10];

    for(int i = 0; i < 10; i++){
        cin >> wejscie[i];
    }

    sort(wejscie, wejscie+10);
    cout << wejscie[9];

    cin.ignore(INT_MAX, 10);
    getchar();
    return 0;
}