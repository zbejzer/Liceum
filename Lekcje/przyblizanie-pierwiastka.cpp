#include <iostream>
#include <math.h>

using namespace std;

float newtonRaphson(float n, float precision)
{
    float x = n/2;

    while( abs(x - (n/x)) > precision )
    {
        x = (x + (n/x))/2;
    }

    return x;
}

int main() {
	float number, precision;
	
	cout << "Podaj liczbe: ";
	cin >> number;
    cout << "Podaj dokladnosc: ";
	cin >> precision;

    cout << newtonRaphson(number, precision);
	
	getchar();
    getchar();
	return 0;
}
