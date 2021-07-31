#include <iostream>
#include <vector>
#include <cstring>
#include "MemCheck.h"

using namespace std;
class Bar{
    char* s;
public:
    Bar(const char* s){
	printf("construct Bar.\n");
	this->s = new char[strlen(s) + 1];
	strcpy(this->s,s);
    }
    ~Bar() { 
	printf("Bar maybe leak? \n");  
	delete []s;
    }
};


class Foo{
    char* s;
public:
    Foo(const char* s){
	printf("construct Foo.\n");
	this->s = new char[strlen(s) + 1];
	strcpy(this->s,s);
    }
   // ~Foo() { delete[] s;}
    ~Foo() { 
	printf("Here maybe leak? \n");  
	delete s;
    }
};

int main(){
    MEM_ON();
    cout << "hello " << endl;
    int *p = new int;
    delete p;
    int *q = new int[3];
    delete []q;

    int *r;
    delete r;

    vector<int> v;
    v.push_back(1);
    printf("\n----------------------------\n");
    Foo s("goodbye");
    Bar bus("ok");
/*
    char *a = new char[2];
    char *b = new char[1];

    a = b;
    delete a;
    delete b;
*/
    MEM_OFF();
}
