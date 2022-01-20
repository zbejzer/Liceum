#include <iostream>

using namespace std;

int symbolNewtona(int n, int k)
{
    if ( k==0 || k==n )
        return 1;
    
    return symbolNewtona( n-1, k-1 ) + symbolNewtona( n-1, k );
}

int main()
{
    int n, k;

    cout << "Podaj dwie liczby: ";
    cin >> n >> k;
    cout << symbolNewtona(n, k);
}