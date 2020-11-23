#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char wej[100];
	bool palindrom = true;
	
	cout << "Wprowadz zdanie " << ": ";
	cin.getline(wej, 100);
	
	char wyj[strlen(wej)];
	
	for(int i=0; i<strlen(wej); i++) {
		if( wej[i] >= 97 && wej[i] <= 122 ) {
			wej[i] = (int)wej[i] - 32;
		}
		wyj[strlen(wej) - 1 - i] = wej[i];
	}
	
	for(int i=0; i<strlen(wej); i++) {
		if( wej[i] != wyj[i] ) {
			palindrom = false;
		}
	}
	
	if( palindrom ) {
		cout << "Wyraz jest palindromem." << endl;
	} else {
		cout << "Wyraz nie jest palindromem." << endl;
	}
	
	getchar();
	return 0;
}
