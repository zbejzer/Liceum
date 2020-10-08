#include <iostream>

using namespace std;

int main() {
	char tab[3][100];
	
	for(int n=0; n<3; n++) {
		cout << "Wprowadz zdanie " << n+1 << " : ";
		cin.getline(tab[n], 100);
	}
	
	for(int n=0; n<3; n++) {
		for(int i=0; i<100; i++) {
			if( (int)tab[n][i] >= 97 && tab[n][i] <= 122 ) {
				tab[n][i] = (int)tab[n][i] - 32;
			}
		}
	}
	
	for(int n=0; n<3; n++) {
		cout << "Dane: " << tab[2-n] << endl;
	}
	
	getchar();
	return 0;
}
