#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CollectionParameter : public vector<string> {};

class Filter{
public:
    void f(CollectionParameter& cp){
        cp.push_back("accumulation");
    }
    void g(CollectionParameter& cp){
        cp.push_back("iterms");
    }
    void h(CollectionParameter& cp){
        cp.push_back("as we go");
    }

};

int main(){
    Filter filler;
    CollectionParameter cp;
    filler.f(cp);
    filler.g(cp);
    filler.h(cp);
    vector<string>::iterator it = cp.begin();
    while(it != cp.end())
        cout << *it++ << "  ";
    cout << endl;
}
