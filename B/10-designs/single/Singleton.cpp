#include <iostream>
using namespace std;

class Singleton{
    static Singleton s;
    int i;
    Singleton(int x) : i(x){}
    Singleton& operator=(Singleton);
    Singleton(const Singleton&);
public:
    static Singleton& instance(){return s;}
    int getVal(){ return i;}
    void setValue(int x){i = x; }
};

Singleton Singleton::s(47);


int main(){
    Singleton& s= Singleton::instance();
    cout << s.getVal() << endl;
    Singleton& s2 = Singleton::instance();
    s2.setValue(9);
    cout << s2.getVal() << endl;
}
