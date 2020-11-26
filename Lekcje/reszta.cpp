#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

const int nominaly[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};

void reszta(int r){
    vector <int> sztuki;

    for(int i=0; r>0; i++)
    {
        int z = r/nominaly[i];
        r -= z*nominaly[i];
        if(z > 0)
            cout << nominaly[i] <<": " << z << endl;
    }
}

int main(){
    int r;

    cout << "Podaj reszte: ";
    cin >> r;

    reszta(r);

    getchar();
    getchar();

    return 0;
}