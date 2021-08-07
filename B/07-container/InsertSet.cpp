//unsorted.
#include <string>
#include <set>
#include <iostream>
#include <fstream>

using namespace std;


int main(int argc, char* argv[]){
    fstream f;
    if(argc > 1)
        f = fstream(argv[1]);
    else
        f = fstream("InsertSet.cpp");

    set<string> words ;
    string word;

    while(f >> word ){
        words.insert(word);
    }

    for(string w : words)
        cout << w << endl;
}
