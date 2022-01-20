#include <iostream>
#include <math.h>

using namespace std;

int NWD(int a, int b)
{
    if( max(a, b) % min(a, b) == 0 )
        return min(a, b);

    return NWD( min(a, b), max(a, b) % min(a, b) );
}

int main()
{
    int a, b;

    cout << "Podaj dwie liczby: ";
    cin >> a >> b;
    cout << NWD(a, b);
}