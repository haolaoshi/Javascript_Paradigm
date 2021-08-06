#include <iostream>

using namespace std;

class Friendly{
    int i;
public:
    Friendly(int theInt){i = theInt; }
    friend void f(const Friendly&);
    void g(){ f(*this);}
};


void h(){
    f(Friendly(1));//ADL argument-dependent look up;
}

void f(const Friendly& fo){
    cout << fo.i << endl;
}

int main()
{
    h();
    Friendly(2).g();
}
