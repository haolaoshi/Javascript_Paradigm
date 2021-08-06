#include <iostream>
using namespace std;


class X{
public:
    void f(){cout << " x.f() " << endl; }
};

class Y{
public:
    void g(){cout << "Y.g() " << endl; }
};

template<typename T> class Z{
    T t;
public:
    void a(){t.f();cout << " Z.a() " << endl; }
    void b(){t.g();cout << " Z.b() " << endl; }
};

int main()
{
    Z<X> zx;
    cout <<"----"<<endl;
    zx.a();
    cout <<"----"<<endl;
    Z<Y> zy;
    cout <<"----"<<endl;
    zy.b();
}
