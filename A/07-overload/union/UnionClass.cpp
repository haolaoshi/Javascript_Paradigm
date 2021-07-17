#include <iostream>

using namespace std;

union U{
private:
    int i;
    float f;
public:
    U(int a);
    U(float b);
    ~U();
    int read_int();
    float read_float();
};

U::U(float a) { f = a; };
U::U(int a ) { i = a; };

U::~U(){ cout << " U :: ~ U () " << endl; }
int U::read_int() { return i; }
float U::read_float() { return f; }

int main()
{
    U x(12), y(1.9f);
    cout << x.read_int() << endl;
    cout << y.read_float() << endl;
}
