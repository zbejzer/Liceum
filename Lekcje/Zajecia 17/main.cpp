#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    ifstream source("sygnaly.txt");
    ofstream answer("wyniki4.txt");

    string firstAnswer = "";
    string secondAnswer;
    vector<string> thirdAnswer;
    int maxLetterCount = 0;
    
    for(int i=1; i<=1000; i++)
    {
        string current;
        set<char> litery;
        bool isInRangeOf10 = true;

        source >> current;
       

        for (int j = 0; j < current.size(); j++)
            litery.insert(current[j]);

        for (int j = 1; j < current.size(); j++)
            if( abs(current[j-1]-current[j]) > 10)  isInRangeOf10 = false;

        if(isInRangeOf10) thirdAnswer.push_back(current);
        
        if(litery.size() > maxLetterCount)
        {
            secondAnswer = current;
            maxLetterCount = litery.size();
        }

        if(i%40 == 0)
            firstAnswer += current[9];
    }

    answer << firstAnswer << endl;
    answer << secondAnswer << " " << maxLetterCount << endl;
    answer << endl;

    for(int i=0; i<thirdAnswer.size(); i++)
        answer << thirdAnswer[i] << endl;

    return 0;
}