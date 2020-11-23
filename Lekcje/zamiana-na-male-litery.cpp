#include <iostream>

using namespace std;

int main() {
	char tab[100];
	
	cout << "Wprowadz teskt: ";
	cin.getline(tab, 100);
	
	cout << "Dane: " << tab << endl;
	for(int i=0; i<100; i++) {
		if( tab[i] >= 97 && tab[i] <= 122 ) {
			tab[i] = (int)tab[i] - 32;
		}
	}
	cout << "Dane: " << tab << endl;
	
	getchar();
	return 0;
}
