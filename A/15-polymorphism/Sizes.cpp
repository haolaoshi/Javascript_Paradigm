#include <iostream>

using namespace std;
class Zero{
public:
    void x() const { cout << " 0 " << endl; }
};
class NoVirtual{
    int a;
public:
    void x() const{}
    int i() const { return 1; }

};

class OneVirtual{
    int a;
public:
    virtual void x() const{}
    int i() const { return 1;}
};

class TwoVirtual{
    int a;
public:
    virtual void x() const{}
    virtual int i() const {return 1;}
};

int main(){
    cout << " int: " << sizeof(int) << endl;
    cout << "NoVirtual: " << sizeof(NoVirtual) << endl;
    cout << " void* " << sizeof(void*)<< endl;
    cout << "OneVirtual:" << sizeof(OneVirtual) <<endl;
    cout << "TwoVirtual:" << sizeof(TwoVirtual) << endl;

    cout << "sizeof(Zero): " << sizeof(Zero) << endl;
}
