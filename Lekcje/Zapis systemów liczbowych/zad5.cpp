#include <iostream>
#include <string>
#include <fstream>
#include <math.h>

#define DATA_COUNT 999

using namespace std;

bool isMinimalSystem(string input)
{
    string number = input.substr(0, input.size() - 1);
    char maxDigit = number[0];

    for(int i=0; i < number.size(); i++)
        if( number[i] >  maxDigit)
            maxDigit = number[i];

    return maxDigit + 1 == input[ input.size() - 1 ];
}

unsigned long long int transformNumber(string input)
{
    string number = input.substr(0, input.size() - 1);
    int baseNumberSystem = input[input.size() - 1] - '0';
    unsigned long long int baseTenNumber = 0;

    for(int i=0; i < number.size(); i++)
    {
        int currentDigit = number[number.size() - i - 1] - '0';
        baseTenNumber += currentDigit * pow(baseNumberSystem, i);
    }

    return baseTenNumber;
}

int main()
{
    ifstream dataInput("liczby.txt");

    unsigned long long int sum = 0;

    for(int i=0; i<DATA_COUNT; i++)
    {
        string currentLine;
        dataInput >> currentLine;

        if( !isMinimalSystem(currentLine) )
            sum += transformNumber(currentLine);
    }

    cout << sum << endl;

    return 0;
}