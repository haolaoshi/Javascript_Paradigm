#include <iostream>

using std::cout;
using std::endl;

void f(double){cout << "fdouble" << endl;}

template<class T> class X{
public:
    void g(){f(1);}
};


void f(int){cout << " fint" << endl;}

int main()
{
    X<int>().g();
}
