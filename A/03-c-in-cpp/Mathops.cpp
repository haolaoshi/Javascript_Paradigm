#include <iostream>

using namespace std;

#define PRINT(STR,VAR)	\
    cout << STR " = " << VAR << endl


int main()
{
    int i , j , k;
    cin >> i;
    cin >> j;

    k = i + j;

    PRINT("i",i);
    PRINT("j",j);
    PRINT("k",k);

    bool res = false;

    int a = 1;
    float b  = 1.0;
    res = a == b;
    PRINT("res",res);

    return 0;
}
