#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


//Problem: iostream >>  lost  newline char

int main()
{
    vector<string> words;
    ifstream in("GetWords.cpp");
    string word;
    string pattern("\n");

    while(in >> word)
	words.push_back(word);

    for(int i=0 ; i < words.size(); i++)
    {
	cout << words[i] <<"  ";
	if(words[i].find_first_of(pattern) != 0 ) cout << endl;
    }
    cout <<endl;

    return 0;
}
