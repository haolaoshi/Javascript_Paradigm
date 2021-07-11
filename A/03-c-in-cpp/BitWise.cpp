#include <iostream>
#include "printBinary.h"

using namespace std;

#define PR(STR,EXPR)	\
    cout << STR; printBinary(EXPR); cout << endl;


int main()
{
    unsigned int val;
    unsigned char a , b;

    cout<< "Enter a number between 0 and 255 :";
    cin >> val;
    a = val;

    PR("a in binary : ", a);
    cout<< "Enter  b number between 0 and 255 : ";
    cin >> val;
    b = val;
    PR("b in binary : ", b);

    PR("a |  b = ", a|b);
    PR("a & b = " , a & b);
    PR("a ^ b = ", a ^ b );
    PR("~a = " , ~a);
    
    unsigned char c = 0x5A;
    PR("c in binary " , c);
    PR(" a |= c = " , a|=c);
    PR(" b &= c = " , b&=c);
    PR(" b &= a = " , b^=a);
    return 0;
}
