#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	char tab[100];
	
	cout << "Podaj imie i nazwisko: ";
	cin.get(tab, 100);
	cout << "Twoje dane osobowe: " << tab << endl;
	cout << "Ponownie podaj imie i nazwisko: ";
	cin.get(tab, 100);
	cout << "Twoje dane osobowe: " << tab << endl;
	
	system("pause");
	return 0;
}
