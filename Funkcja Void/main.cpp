#include <iostream>

using namespace std;

int a, b;

void dane() {
	cout<<"Podaj a i b: ";
	cin>>a>>b;
}

int main() {
	dane();
	
	cin.sync();
	getchar();
	
	return 0;
}
