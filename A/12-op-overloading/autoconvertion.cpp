#include <iostream>
using namespace std;

class One{
public:
    One(){cout << " Create One ." << endl; }
};

class Two{
public:
    explicit    Two(const One&){ cout << " Create Two. " << endl; }
};

void f(Two){ cout << " in f() " << endl; }

int main()
{
    One one;
//could not convert ‘one’ from ‘One’ to ‘Two’
 //   f(one);
    f(Two(one));
}

