#include <iostream>

using namespace std;

int y;
int &r = y;

const int& q = 12;

int x = 0;
int &a = x;

int main()
{
    y   = 100;
    x -= 1;
    cout << " r = " << r << endl; 
    cout << " q = " << q << endl;
    cout << " x = " << a << endl;
}
