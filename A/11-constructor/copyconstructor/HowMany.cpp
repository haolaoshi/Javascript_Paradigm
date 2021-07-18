#include <fstream>
#include <iostream>
#include <string>

using namespace std;

ofstream out("HowMany.txt");


class HowMany{
    static int objectCount;
public:
    HowMany(){ objectCount++; cout << " Constructor : " << objectCount << endl; }
    static void print(const string& msg = " "){
	if(msg.size() != 0 ) out << msg << " : " ;
	cout << "print :  object count = " << objectCount << endl;
    }
    ~HowMany(){
	objectCount--;
	cout << "~HowMany(): " << objectCount << endl;
    }
};

int HowMany::objectCount = 0;
HowMany f(HowMany x){
    x.print("x argu indised f()");
    return x;
}

int main(){
    HowMany h;
    HowMany::print("after construct h " );
    HowMany h2 = f(h);
    HowMany::print("after call to f()");


}
