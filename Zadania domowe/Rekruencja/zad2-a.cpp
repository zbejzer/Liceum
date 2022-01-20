#include <iostream>

using namespace std;

int arytmetyczny(int a, int r, int n)
{
    if( n < 2)
        return a;

    return arytmetyczny(a, r, n-1) + r;
}

int main()
{
    int a, r, n;

    cout << "Podaj pierwszy wyraz ciagu: ";
    cin >> a;
    cout << "Podaj roznice ciagu: ";
    cin >> r;
    cout << "Podaj wyraz ciagu do oblcizenia: ";
    cin >> n;
    cout << arytmetyczny(a, r, n);
}