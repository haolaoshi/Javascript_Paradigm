#include <iostream>
#include <typeinfo>

using namespace std;

struct PolyBase{ virtual ~PolyBase(){} };

struct PolyDer : PolyBase{PolyDer(){} };

struct NonPolyBase {};

struct NonPolyDer : NonPolyBase{ NonPolyDer(int){} };

int main(){
    const PolyDer pd;
    const PolyBase* ppb = &pd;

    cout << typeid(ppb).name() << endl;
    cout << typeid(*ppb).name() << endl;

    cout << boolalpha << (typeid(*ppb) == typeid(pd)) << endl;
    cout << (typeid(PolyDer) == typeid(const PolyDer)) << endl;

    const NonPolyDer npd(1);
    const NonPolyBase* bpb = &npd;

    cout << typeid(bpb).name() << endl;
    cout << typeid(*bpb).name() << endl;

    cout << (typeid(*bpb) == typeid(npd)) << endl;

    int i;
    cout << typeid(i).name() << endl; 


}
