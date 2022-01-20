#include <iostream>

using namespace std;

int geometryczny(int a, int q, int n)
{
    if( n < 2)
        return a;

    return geometryczny(a, q, n-1)*q;
}

int main()
{
    int a, q, n;

    cout << "Podaj pierwszy wyraz ciagu: ";
    cin >> a;
    cout << "Podaj iloczyn ciagu: ";
    cin >> q;
    cout << "Podaj wyraz ciagu do oblcizenia: ";
    cin >> n;
    cout << geometryczny(a, q, n);
}