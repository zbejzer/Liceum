#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

bool isPow(int number, int base)
{
    int k=0;

    while(pow(base, k) <= number)
    {
        if(pow(base, k) == number) return true;
        k++;
    }

    return false;
}

int main()
{
    ifstream wejscie("liczby.txt");

    int counter = 0;

    for(int i=0; i<500; i++)
    {
        int cNumber;

        wejscie >> cNumber;

        if(isPow(cNumber, 3))
        {
            counter++;
        }
    }

    cout << counter;

    return 0;
}