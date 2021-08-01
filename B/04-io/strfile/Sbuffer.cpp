#include <fstream>
#include <iostream>

#include "../../require.h"

using namespace std;

int main(){
    ifstream in("Sbuffer.cpp");
    assure(in);
    streambuf& sb = *cout.rdbuf();
    while(!in.get(sb).eof()){
        if(in.fail())
            in.clear();
        cout << char(in.get());
    }
}
