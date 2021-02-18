#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, iloscZestawow = 0, liczby[2] = {0, 0};
    vector <int> schody;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        liczby[1] = liczby[0];
        cin >> liczby[0];
        
        if(liczby[0] == 1)
        {
            iloscZestawow++;
            schody.push_back(liczby[1]);
        }

        if(i == n-1)
            schody.push_back(liczby[0]);
    }

    cout << iloscZestawow << endl;
    
    for(int i=1; i<schody.size(); i++)
        cout << schody[i] << " ";

    return 0;
}