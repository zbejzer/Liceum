#include <iostream>

using namespace std;

int fibonacciLoop(int n){
    int numbers[3] = {1, 1, 1};

    for( int i=2; i<n; i++ ){
        numbers[2] = numbers[0] + numbers[1];
        numbers[0] = numbers[1];
        numbers[1] = numbers[2];
    }

    return numbers[2];
}

int fibonacciRec(int n){
    if( n<=2 )
        return 1;

    return fibonacciRec(n-1) + fibonacciRec(n-2);   
}

int main(){
    int n;

    cout << "Enter n-number of fibonacci sequence: ";
    cin >> n;

    cout << "Loop: " <<  fibonacciLoop(n) << endl;
    cout << "Recursion: " << fibonacciRec(n) << endl;

    return 0;
}