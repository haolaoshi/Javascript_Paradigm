//sorted.

#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include "../require.h"

using namespace std;

void wordSet( const char* fileName){
    ifstream source(fileName);
    string word;
    set<string> words;
    while(source >> word)
        words.insert(word);
    copy(words.begin(),words.end(),ostream_iterator<string>(cout,"\n"));

    cout << "Numbers total : " << words.size() << endl; 
}

int main(int argc, char* argv[])
{
    if(argc > 1)
        wordSet(argv[1]);
    else
        wordSet("WordSet.cpp");
}

