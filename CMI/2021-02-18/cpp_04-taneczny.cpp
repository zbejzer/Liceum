#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, koszt = 0, ceny[2];
    bool mozliwy = true;
    cin >> n >> ceny[0] >> ceny[1];

    int tancerki[n];

    for(int i=0; i<n; i++)
        cin >> tancerki[i];

    for(int i=0; i<n/2; i++)
    {
        switch (tancerki[i])
        {
        case 0:
        {
            if(tancerki[n-i-1] == 0)
                koszt += min(ceny[0], ceny[1]) * 2;
            else
                koszt += ceny[ tancerki[n-i-1] - 1 ];
            break;
        }

        case 1:
        {
            if(tancerki[n-i-1] == 0)
                koszt += ceny[0];
            else if(tancerki[n-i-1] == 1) {}
            else
                mozliwy = false;

            break;
        }

        case 2:
        {
            if(tancerki[n-i-1] == 0)
                koszt += ceny[1];
            else if(tancerki[n-i-1] == 2) {}
            else
                mozliwy = false;

            break;
        }

        default:
            break;
        }

        if(!mozliwy)
            break;
    }

    if( (n%2 == 1) && (tancerki[(n+1)/2] == 0) )
        koszt += min(ceny[0], ceny[1]);

    if(mozliwy)
        cout << koszt;
    else
        cout << "NIE";

    return 0;
}