#include <string>
#include <iostream>
#include <cassert>
#include "MemCheck.h"
using namespace std;

int main(){
    MEM_ON();
    string imBland;
    string heyMom("where are my socks.");
    string standard = "enn .space on wide angle disperaisont ? " ;

    string useTheOneAgain(standard);

    cout << "----------------------" << endl;

    string s4(standard,0,100);
    cout << s4 << endl;
    s4 += " the moon";
    cout << s4 << endl;

    string s5 = s4.substr(10,3);
    cout << s5 << endl;

    string s6(heyMom.begin(),heyMom.end());
    cout << s6 << endl;
    
    assert(s6 == heyMom);
    string a = "aaaaa";
    string b(5, 'a');
    assert(a == b);


    cout << " -------------------------" << endl;

    string t("A piece of text");
    string tag("$tag$");
    t.insert(8,tag + ' ');
    cout << t << endl; 
    t.replace(9,3,"xxx");
    cout << t << endl;

    int p = t.find("x");
    assert(9 == p );


    int p2 = t.find("*");
    if( p2 == string::npos) 
	cout << " cannot find a star like '*' " << endl;
    MEM_OFF();
}
