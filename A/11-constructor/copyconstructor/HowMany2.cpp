#include <fstream>
#include <string>
#include <iostream>

using namespace std;

ofstream out("howmany2.txt");

class HowMany2{
    string name;
    static int objectCount;
public:
    HowMany2(const string& id = "") : name(id){
	++objectCount;
	print("HowMany2()");
    }
    ~HowMany2(){
	--objectCount;
	print("~HowMany2()");
    }
    HowMany2(const HowMany2& h) : name(h.name){
	name += " copy";
	++objectCount;
	print("HowMany2 (const HowMany2 & ) " );
    }
    
    void print(const string& msg = " " ) const {
	if(msg.size() != 0)
	    out << msg <<  endl;
	out << '\t' << name << " : " 
	    << "objectCount = " << objectCount << endl;
    }
};

int HowMany2::objectCount = 0;


HowMany2 f(HowMany2 x){
    x.print("x argu inside f()");
    out << " returning from f() " << endl;
    return x;

}


int main(){
    HowMany2 h("h");
    out << " Enter f() " << endl;
    HowMany2 h2 = f(h);
    h2.print(" h2 after call to f()" );
    out << " Call f() , no return value " << endl;
    f(h);
    out << " After call to f() " << endl;
}
