#include <iostream>
#include <limits.h>
#include <iomanip>
using namespace std;

int main() {
	int n;
	cin>>n;
	
	for(int i=1; i<=n; i++){
		for(int j=0; j<n-i+1; j++){
			cout<<"*";
		}
		cout<<endl;
	}
	
	cin.ignore(INT_MAX, '\n');
	getchar();
	return 0;
}
