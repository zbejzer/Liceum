// Wersja 2.0.0

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <chrono> 
#include <ratio>
#include <algorithm>
using namespace std::chrono; 
using namespace std;

double selection(int tab[], int n)
{  
    auto start = high_resolution_clock::now();

    int i, j, min_index;  
    for (i = 0; i < n-1; i++)  
    {  
        min_index = i;
        for (j = i+1; j < n; j++)  
            if (tab[j] < tab[min_index])  
                min_index = j;  
        swap(tab[min_index], tab[i]);  
    }

    auto end = high_resolution_clock::now(); 
    auto duration = duration_cast<nanoseconds>(end - start).count();
    return duration  * 1.0 / nano::den;
}  

double alg_sort(int tab[], int n)
{
    auto start = high_resolution_clock::now();

    sort(tab, tab+n);

    auto end = high_resolution_clock::now(); 
    auto duration = duration_cast<nanoseconds>(end - start).count();
    return duration * 1.0 / nano::den;
}

double bucket(int tab[], int n)
{
    auto start = high_resolution_clock::now(); 

    map <int, vector <int>> b;                      // Tworzenie n wiaderek
    int max_value = *max_element(tab, tab+n) + 1;   // Wyznaczanie maksymalnej wartosci w tablicy
    for (int i=0; i<n; i++)                         // Wkladanie do odpowiedniego wiaderka
    {
        int bi = 1.0 * n * tab[i] / max_value;      // Wyznaczanie indexu liczby
        b[int(bi)].push_back(tab[i]);
    }

    for (int i=0; i<n; i++)                         // Sortowanie kazdego wiaderka
       sort(b[i].begin(), b[i].end());
 
    int index = 0;
    for (int i = 0; i < n; i++)                     // Przenoszenie do wlasciwej tablicy
        for (int j = 0; j < b[i].size(); j++)
          tab[index++] = b[i][j];

    auto end = high_resolution_clock::now(); 
    auto duration = duration_cast<nanoseconds>(end - start).count();
    return duration * 1.0 / nano::den;
}

double bubble(int tab[], int n)
{
    auto start = high_resolution_clock::now();

    for(int i=0; i<n-1; i++)
        for (int j=0; j<n-i-1; j++)  
            if (tab[j] > tab[j+1])  
                swap(tab[j], tab[j+1]);

    auto end = high_resolution_clock::now(); 
    auto duration = duration_cast<nanoseconds>(end - start).count();
    return duration * 1.0 / nano::den;
}

double insert(int tab[], int n)
{
    auto start = high_resolution_clock::now(); 

    for(int i=1; i<n; i++)
    {
        int elem = tab[i];
        int k = i-1;
        
        while(k >= 0 && tab[k] > elem)
        {
            tab[k+1] = tab[k];
            k--;
        }
        tab[k+1] = elem;
    }

    auto end = high_resolution_clock::now(); 
    auto duration = duration_cast<nanoseconds>(end - start).count();
    return duration * 1.0 / nano::den;
}

void odPdoK(int tab[], int n)
{
    for(int i=0; i<n; i++)
        tab[i] = i;
}
void odKdoP(int tab[], int n)
{
    for(int i=0; i<n; i++)
        tab[i] = n-i;
}

void losowo(int tab[], int n)
{
    for(int i=0; i<n; i++)
        tab[i] = rand() % 500 + 1;
}

int main()
{
    ofstream f_wyj ("pomiary.txt");
    srand(time(NULL));

    int rozmiary[] {200, 500, 1000, 10000, 100000};

    for(int t=0; t<3; t++)
    {
        for(int i=0; i<5; i++)
        {
            int tablicaWzor[rozmiary[i]], tablica[rozmiary[i]];
            switch (t)
            {
            case 0:
                odPdoK(tablicaWzor, rozmiary[i]);
                cout << "Optymistyczny";
                f_wyj << "Optymistyczny";
                break;
            case 1:
                odKdoP(tablicaWzor, rozmiary[i]);
                cout << "Pesymistyczny";
                f_wyj << "Pesymistyczny";
                break;
            case 2:
                losowo(tablicaWzor, rozmiary[i]);
                cout << "Random";
                f_wyj << "Random";
                break;
            }

            cout << " [" << rozmiary[i] << "]\n";
            f_wyj << " [" << rozmiary[i] << "]\n";
            
            copy(tablicaWzor, tablicaWzor+rozmiary[i], tablica);
            f_wyj << bubble(tablica, rozmiary[i]) << endl;
            cout << "Bubble, " << flush;
            copy(tablicaWzor, tablicaWzor+rozmiary[i], tablica);
            f_wyj << bucket(tablica, rozmiary[i]) << endl;
            cout << "Bucket, " << flush;
            copy(tablicaWzor, tablicaWzor+rozmiary[i], tablica);
            f_wyj << insert(tablica, rozmiary[i]) << endl;
            cout << "Insertion, " << flush;
            copy(tablicaWzor, tablicaWzor+rozmiary[i], tablica);
            f_wyj << alg_sort(tablica, rozmiary[i]) << endl;
            cout << "Algorithm, " << flush;
            copy(tablicaWzor, tablicaWzor+rozmiary[i], tablica);
            f_wyj << selection(tablica, rozmiary[i]) << endl;
            cout << "Selection\n" << flush;
        }
        cout << "\n" << endl;
    }
    cout << "KONIEC" << flush;

    getchar();
    getchar();
    return 0;
}