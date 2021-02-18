#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{
    int n;
    int maxN = numeric_limits<int>::min();
    int minN = numeric_limits<int>::max();
    
    cin >> n;               // liczba pozostalych obrazow

    for(int i=0; i<n; i++)
    {
        int paintingNumber;
        cin >> paintingNumber;       // wczytanie numerow pozostalych obrazow

        if(paintingNumber > maxN)
            maxN = paintingNumber;
        if(paintingNumber < minN)
            minN = paintingNumber;
    }
    
    cout << maxN - minN - n + 1;
    return 0;
}