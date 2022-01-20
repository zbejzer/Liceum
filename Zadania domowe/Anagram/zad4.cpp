#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream input_data("anagram.txt");

    for(int i=0; i<200; i++)
    {
        bool isAllAnagrams = true;
        string baseWord, textRow = "";
        unordered_map<char, int> baseWordMap;

        input_data >> baseWord;
        textRow += baseWord + " ";

        for(int j=0; j<baseWord.size(); j++)
            baseWordMap[ baseWord.at(j) ]++;

        for(int j=0; j<4; j++)
        {
            string newWord;
            unordered_map<char, int> newWordMap;

            input_data >> newWord;
            textRow += newWord + " ";

            for(int k=0; k<newWord.size(); k++)
                newWordMap[ newWord.at(k) ]++;

            if( newWordMap != baseWordMap )
                isAllAnagrams = false;
        }

        if( isAllAnagrams )
            cout << textRow << endl;
    }

    return 0;
}