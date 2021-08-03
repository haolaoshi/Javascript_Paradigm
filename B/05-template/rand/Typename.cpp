#include <iostream>
using namespace std;

template<class T> class X{
    typename  T::id  i;
public:
    void f() { cout << "f();" << endl; i.g();}
};

class Y{
public:
    class id{
    public:
        void g(){ cout << " g() ; " << endl;}
    };

};

int main(){
    X<Y> xy;
    xy.f();
}
