#include "Mem.h"

#include <cstring>
#include <iostream>

using namespace std;

class MyString{
    Mem* buf;
public:
    MyString();
    MyString(char *str);
    ~MyString();

    void concat(char* str);
    void print(ostream& os);
};

MyString::MyString() { buf = 0; }

MyString::MyString(char *str){
    buf = new Mem(strlen(str) + 1);
    strcpy((char*)buf->pointer(),str);
}

void MyString::concat(char* str)
{
    if(!buf) buf = new Mem();
    strcat((char*)buf->pointer(buf->msize() + strlen(str) + 1) , str);
}

void MyString::print(ostream& os){
    if(!buf) return;
    os << buf->pointer() << endl;
}

MyString::~MyString(){delete buf;}

int main()
{
    char *s1 = (char*)"My Test String";
    MyString s(s1);
    s.print(cout);
    s.concat(" Som additional surr");
    s.print(cout);

    MyString s2;
    s2.concat("Using default construct");
    s2.print(cout);
}
