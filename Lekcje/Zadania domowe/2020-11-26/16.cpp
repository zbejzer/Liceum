#include <iostream>
#include <math.h>
#include <limits.h>
#include <vector>
#include <utility>

using namespace std;

int nww(int, int);
int nwd(int, int);
pair <int, int> dodawanie(int, int, int, int);

int main(){
    int l_a, m_a, l_b, m_b;
    pair <int, int> wynik;

    cout << "Podaj licznik i mianownik ulamka a: ";
    cin >> l_a >> m_a ;
    cout << "Podaj licznik i mianownik ulamka b: ";
    cin >> l_b >> m_b ;

    wynik = dodawanie(l_a, m_a, l_b, m_b);
    cout << "Suma tych ulamkow: " << wynik.first << "/" << wynik.second << "\n";
    
	cin.ignore(INT_MAX, '\n');
	getchar();
	return 0;
}

int nwd(int a, int b){
    while(a > 0)
    {
        a %= b;
        b -= a;
    }

    return b;
}

int nww(int a, int b){
    return a*b/nwd(a, b);
}

pair <int, int> dodawanie(int l_a, int m_a, int l_b, int m_b){
    int wsp_mian = nww(m_a, m_b), wsp_dziel;
    pair <int, int> wynik;

    l_a *= wsp_mian/m_a;
    l_b *= wsp_mian/m_b;
    m_a = wsp_mian;
    l_a += l_b;
    wsp_dziel = nwd(l_a, m_a);
    l_a /= wsp_dziel;
    m_a /= wsp_dziel;

    wynik.first = l_a;
    wynik.second = m_a;

    return wynik;
}