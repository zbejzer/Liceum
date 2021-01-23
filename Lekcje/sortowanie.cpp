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


void babelkowe(int tab[], int n)
{
    for(int i=0; i<n; i++)
		for(int j=1; j<n-i; j++)
        {
            // porownywanie
            if(tab[j-1]>tab[j])
            {
                //zamiana miejscami tab[i] i tab[min]
                int temp = tab[j];
                tab[j] = tab[j-1];
                tab[j-1] = temp;
            }
        }
}

void wypisz(int tab[], int n)
{
    for(int i=0; i<n; i++)
        cout << tab[i] << endl;
}

int main(){
    int n, metoda;

    cout << "Podaj ilosc liczb do posortowania: \n";
    cin >> n;

    int tab[n];
    
    for(int i=0; i<n; i++)
    {
        cout << "Podaj liczbe " << i << ": ";
        cin >> tab[i];
    }

    cout << "Wybierz metode sortowania: \n";
    cout << "[0] Sortowanie przez wybieranie. \n";
    cout << "[1] Sortowanie babelkowe. \n";
    cin >> metoda;

    switch(metoda)
    {
        case 0:
        {
            wybor(tab, n);
            break;
        }
        case 1:
        {
            babelkowe(tab, n);
            break;
        }
    }

    wypisz(tab, n);

    getchar();
    getchar();

    return 0;
}