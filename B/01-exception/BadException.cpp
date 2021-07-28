#include <exception>
#include <iostream>
#include <cstdio>

using namespace std;

class A{};
class B{};

void my_handler(){
    cout << " terminate called " << endl;
    exit(0);
}

void my_unhandle1(){throw A(); }
void my_unhandle2(){throw; }

void t(){throw B();}
void f() throw(A){t();}

void g() throw(A, bad_exception){t();}

int main(){
    set_terminate(my_handler);
    set_unexpected(my_unhandle1);
    try{
	f();
    }catch(A&){
	cout << " caught an A from f()" << endl;
    }
    
    set_unexpected(my_unhandle2);
    try{
	g();
    }catch(bad_exception&){
	cout << " caught a badexception fro mg" << endl;
    }

    try{
	f();
    }catch(...){
	cout << " this will never print. " << endl;
    }
}
