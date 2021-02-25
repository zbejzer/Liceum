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

    ofstream debug("selection.txt");
    debug << "\nSTART [" << n << "]\n";
    for(int i=0; i<n; i++)
        debug << tab[i] << endl;

    return duration  * 1.0 / nano::den;
}  

double alg_sort(int tab[], int n)
{
    auto start = high_resolution_clock::now();

    sort(tab, tab+n);

    auto end = high_resolution_clock::now(); 
    auto duration = duration_cast<nanoseconds>(end - start).count();

    ofstream debug("alg_sort.txt");
    debug << "\nSTART [" << n << "]\n";
    for(int i=0; i<n; i++)
        debug << tab[i] << endl;

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

    ofstream debug("bucket.txt");
    debug << "\nSTART [" << n << "]\n";
    for(int i=0; i<n; i++)
        debug << tab[i] << endl;

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

    ofstream debug("bubble.txt");
    debug << "\nSTART [" << n << "]\n";
    for(int i=0; i<n; i++)
        debug << tab[i] << endl;
    
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

    ofstream debug("insert.txt");
    debug << "\nSTART [" << n << "]\n";
    for(int i=0; i<n; i++)
        debug << tab[i] << endl;

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

    int rozmiary[5] {200, 500, 1000, 10000, 100000};
    int tab1[rozmiary[0]], tab2[rozmiary[1]], tab3[rozmiary[2]], tab4[rozmiary[3]], tab5[rozmiary[4]];
    int *tablica[5] {tab1, tab2, tab3, tab4, tab5};
    

    for(int t=0; t<3; t++)
    {
        for(int i=0; i<5; i++)
        {
            switch (t)
            {
            case 0:
                odPdoK(tablica[i], rozmiary[i]);
                cout << "Optymistyczny";
                f_wyj << "Optymistyczny";
                break;
            case 1:
                odKdoP(tablica[i], rozmiary[i]);
                cout << "Pesymistyczny";
                f_wyj << "Pesymistyczny";
                break;
            case 2:
                losowo(tablica[i], rozmiary[i]);
                cout << "Random";
                f_wyj << "Random";
                break;
            }

            cout << " [" << rozmiary[i] << "]\n";
            f_wyj << " [" << rozmiary[i] << "]\n";

            f_wyj << bubble(tablica[i], rozmiary[i]) << endl;
            cout << "Bubble, " << flush;
            f_wyj << bucket(tablica[i], rozmiary[i]) << endl;
            cout << "Bucket, " << flush;
            f_wyj << insert(tablica[i], rozmiary[i]) << endl;
            cout << "Insertion, " << flush;
            f_wyj << alg_sort(tablica[i], rozmiary[i]) << endl;
            cout << "Algorithm, " << flush;
            f_wyj << selection(tablica[i], rozmiary[i]) << endl;
            cout << "Selection\n" << flush;
        }
        cout << "\n" << endl;
    }
    cout << "KONIEC" << flush;

    getchar();
    getchar();
    return 0;
}