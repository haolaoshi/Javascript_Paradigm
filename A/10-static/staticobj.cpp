#include <iostream>

using namespace std;

class X{
    int i;
public:
//    X(){ i = 0; }
    X(int ii = 0) : i(ii) {}
    ~X(){ cout << " X::~X()" << endl; }

};

void f(){
    static X x2;
    static X x1(47);
}

int main()
{
    f();
}
