#include <iostream>
using namespace std;



class A{
    int i[100];
};

struct B{
    void f();
};

void B::f(){}


int main()
{
    cout << "sizeof A : " << sizeof(A)<<endl;
    cout << "sizeof B : " << sizeof(B) << endl;

    return 0;
}
