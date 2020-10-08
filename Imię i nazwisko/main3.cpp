#include <iostream>

using namespace std;

int main() {
	char tab[100];
	
	cout << "Podaj imie i nazwisko: ";
	cin.getline(tab, 100);
	cout << "Twoje dane osobowe: " << tab << endl;
	cout << "Ponownie podaj imie i nazwisko: ";
	cin.getline(tab, 100);
	cout << "Twoje dane osobowe: " << tab << endl;
	
	getchar();
	return 0;
}
