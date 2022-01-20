#include <iostream>

using namespace std;

int sumaCyfr(int x)
{
    if( x < 10)
        return x;

    return sumaCyfr(x / 10) + (x % 10);
}

int main()
{
    int x;

    cout << "Podaj liczbe: ";
    cin >> x;
    cout << sumaCyfr(x);
}