#include <fstream>
#include <iostream>
#include <string>
#include "Stash3.h"
#include <cassert>

using namespace std;

int main()
{
    Stash intStash(sizeof(int));
    for(int i = 0 ; i < 100; i++)
	intStash.add(&i);

    for(int j = 0; j < intStash.count(); j++)
	cout << "intStash.fetch(" << j << ") = " 
	    << *(int*)intStash.fetch(j) 
	    << endl;
    
    const int buffsize = 80;
    Stash stringStash(sizeof(char) * buffsize , 100);
    ifstream in("Stash3Test.cpp");
    if(!in){
	cerr << " Error read Stash3Text.cpp" << endl;
	exit(1);
    }
   // assert(in.c_str().empty()); 
 //   assert(in == "Stash3Test.cpp");
    string line;

    while(getline(in,line))
    {
	stringStash.add((char*)line.c_str());
	int k =0; 
	char* cp;
	while((cp = (char*)stringStash.fetch(k++)) != 0)
	    cout << " stringStash.fetch(" << k << " ) = " 
		<< cp << endl;
    }

}///:~
