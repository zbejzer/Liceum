#include <iostream>

using namespace std;

int main() {
	char tab[100];
	int counter = 1;
	
	cout << "Wprowadz teskt: ";
	cin.getline(tab, 100);
	
	for(int i=0; i<100; i++) {
		if( tab[i] == 32 ) {
			counter++;
		}
	}
	cout << "W zdaniu jest tyle wyrazow: " << counter << endl;
	
	getchar();
	return 0;
}
