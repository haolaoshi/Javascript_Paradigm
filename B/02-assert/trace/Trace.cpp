#include <iostream>
#include <fstream>
#include <cassert>
#include "./Trace.h"
#include "../require.h"

using namespace std;

#define TRACEON

int main(){
    ifstream f("Tracest.cpp");
    assure(f,"Tracest.cpp");
    cout << f.rdbuf() ; 
}
