#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include <iostream>
#include <sstream>
#include "../require.h"

using namespace std;


int main(int argc, char* argv[])
{
    const char* fname = "StringVector.cpp";
    if(argc > 1) fname = argv[1];
    ifstream in(fname);

    assure(in,fname);
    vector<string> strings;

    string line;

    while(getline(in,line))
        strings.push_back(line);

    int i = 1;
    vector<string>::iterator w;
    for(w = strings.begin(); w != strings.end(); w++){
        ostringstream ss;
        ss << "[" << i++ << "]" ;
        *w = ss.str() + ":" + *w; 
    }

    copy(strings.begin(), strings.end(),ostream_iterator<string>(cout, "\n"));


}
