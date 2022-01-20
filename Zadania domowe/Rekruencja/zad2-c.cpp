#include <iostream>

using namespace std;

int fibonacci(int n)
{
    if( n < 3)
        return 1;

    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int n;

    cout << "Podaj wyraz ciagu Fibonacciego: ";
    cin >> n;
    cout << fibonacci(n);
}