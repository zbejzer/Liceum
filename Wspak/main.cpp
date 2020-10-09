#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char wej[100], wyj[100];
	
	cout << "Wprowadz zdanie " << " : ";
	cin.getline(wej, 100);
	
	for(int i=0; i<strlen(wej); i++) {
		wyj[strlen(wej) - 1 - i] = wej[i];
	}
	
	cout << "Zdanie wspak: " << wyj << endl;
	
	getchar();
	return 0;
}
