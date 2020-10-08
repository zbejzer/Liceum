#include <iostream>

using namespace std;

int main() {
	char tab[5] = {'a', 'b', '\0'};
	cout << tab << endl;
	
	char tab2[] = {'a', 'b', '\0'};
	cout << tab2 << endl;
	
	char tab3[] = "Ala ma kota";
	cout << tab3 << endl;
	
	getchar();
	return 0;
}
