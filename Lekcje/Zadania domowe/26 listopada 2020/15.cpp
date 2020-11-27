#include <iostream>
#include <math.h>
#include <limits.h>
#include <vector>

using namespace std;

int nww(int, int);
int nwd(int, int);

int main(){
    int a, b;

    cout << "Podaj a i b do obliczenia NWW: ";
    cin >> a >> b;
    cout << "NWW z " << a << " i " << b << ": ";

    cout << nww(a,b) << endl;
    
	cin.ignore(INT_MAX, '\n');
	getchar();
	return 0;
}

int nwd(int a, int b){
    while(a > 0)
    {
        a %= b;
        b -= a;
    }

    return b;
}

int nww(int a, int b){
    return a*b/nwd(a, b);
}