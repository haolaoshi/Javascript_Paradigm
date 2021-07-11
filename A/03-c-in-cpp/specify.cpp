#include <iostream>


/*
    long , short , signed , unsigned 
    
    are specifier to change inner-type defines;

    When we talk about short int and long int , keyword "int" is optional;

    so, long is to say "long int", also long long is to say " long long int";


    unsigned char = 1;
    unsigned short int = 2;
    long int = 4;
    long long int = 8;

**/
using namespace std;


int main()
{
    char c;
    cout<<"\n(1)char="<<sizeof(c)<<endl;

    unsigned char uc;
    cout<<"\n(2)unsigned char = "<<sizeof(uc)<<endl;

    int i;
    cout<<"\n(4)int="<<sizeof(i)<<endl;

    unsigned int ui;
    cout<<"\n(4)unsigned int="<<sizeof(ui)<<endl;

    short int si;
    cout<<"\n(2)short i="<<sizeof(si)<<endl;

    short ssi;
    cout<<"\n(2)short = "<<sizeof(ssi)<<endl;

    unsigned short int usi;
    cout<<"\n(4)unsigned short i = "<<sizeof(usi)<<endl;

    unsigned short ussi;
    cout<<"\n(4)unsigned short = "<<sizeof(ussi)<<endl;

    float f;
    cout<<"\n(4)float="<<sizeof(f)<<endl;

    double d;
    cout<<"\n(8)double = "<<sizeof(d)<<endl;

    long double ld;
    cout<<"\n(16)long double="<<sizeof(ld)<<endl;

    long l;
    cout<<"\n(4) long = "<<sizeof(l)<<endl;

    long long  ll;
    cout<<"\n(64)long long = "<<sizeof(ll)<<endl;
}
