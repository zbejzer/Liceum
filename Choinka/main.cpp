#include <iostream>
#include <limits.h>
#include <iomanip>
using namespace std;

int main() {
	int w, h, m=1;
	cin>>h;
	w=h*2;
	
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if( j>(w/2)-m && j<(w/2)+m ){
				cout<<"*";
			}else{
				cout<<" ";
			}
		}
		m++;
		
		cout<<endl;
	}
	
	for(int i=0; i<(h/2); i++){
		for(int j=0; j<w; j++){
			if( j>(w/2)-(w/8) && j<(w/2)+(w/8) ){
				cout<<"*";
			}else{
				cout<<" ";
			}
		}
		cout<<endl;
	}
	
	
	cin.ignore(INT_MAX, '\n');
	getchar();
	return 0;
}
