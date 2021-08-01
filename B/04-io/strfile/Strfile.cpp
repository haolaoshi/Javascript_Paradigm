#include <fstream>
#include <iostream>
#include "../../require.h"

using namespace std;


int main(){
    const int SZ = 100;
    char buf[SZ];

    {
        ifstream in("Strfile.cpp");
        assure(in,"Strfile.cpp");
        ofstream out("Strfile.out");
        assure(out,"Strfile.out");
        int i = 1;
        
        while( in.get(buf,SZ)) {
            in.get();
            cout << buf << endl;
            out << i++ << ": " << buf << endl;
        }
    }
/*
    ifstream in("Strfile.out");
    assure(in,"Strfile.out");
    while(in.getline(buf,SZ)){
        char* cp = buf;
        while(*cp != '"')
            ++cp;
        cp += 2;
        cout << cp << endl;
    }
    */
}


