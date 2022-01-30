#include <iostream>

using namespace std;

int nwd(int a, int b){
    if(a != b)
    {
        if(a > b)
            return nwd(a-b, b);
        else
            return nwd(a, b-a);
    } else
        return a;
}

int nww(int a, int b)
{
    return (a*b)/nwd(a,b);
}

int main()
{
    int a, b;

    cout << "Podaj a: ";
    cin >>  a;
    cout << "Podaj b: ";
    cin >>  b;
    cout << nww(a, b) << endl;



    getchar();
    return 0;
}