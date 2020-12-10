#include <iostream>
#include <limits.h>

using namespace std;

int fibonacci(int a){
    if(a<2)
        return 1;

    return fibonacci(a-1) + fibonacci(a-2);   
}

int main(){
    int n = 6;
    bool wybrano = false;

    cout << "6 pierwszych liczb fibonacciego to: \n";

    for(int i=0; i<n; i++)
        cout << fibonacci(i) << "\n";
    
    cin.ignore(INT_MAX, '\n');
    getchar();
    return 0;
}