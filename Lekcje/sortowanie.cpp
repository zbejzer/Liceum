#include <iostream>
#include <limits>

using namespace std;

void wybor(int tab[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min = i;

        // szukanie indeksu najmniejszej liczby
        for(int j=i+1; j<n; j++)
        {
            if(tab[j] < tab[min])
                min = j;
        }

        // zamiana tab[i] i tab[min]
        int temp = tab[i];
        tab[i] = tab[min];
        tab[min] = temp;
    }
}

void wypisz(int tab[], int n)
{
    for(int i=0; i<n; i++)
        cout << tab[i] << endl;
}

int main(){
    int n;

    cout << "Podaj ilosc liczb do posortowania: \n";
    cin >> n;

    int tab[n];
    
    for(int i=0; i<n; i++)
    {
        cout << "Podaj liczbe " << i << ": ";
        cin >> tab[i];
    }

    wybor(tab, n);

    wypisz(tab, n);

    getchar();
    getchar();

    return 0;
}