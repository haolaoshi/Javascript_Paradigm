#include <fstream>
#include <iostream>
#include "../../require.h"

using namespace std;

int main(){
    ifstream in("Stype.cpp");
    assure(in,"Stype.cpp");
    cout << in.rdbuf() ;
}
