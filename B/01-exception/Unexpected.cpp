#include <exception>
#include <iostream>

using namespace std;

class Up{};
class Fit{};

void g();

void f(int i) throw(Up,Fit){
    switch(i){
	case 1: throw Up();
	break;
	case 2: throw Fit();
	break;
	default:
	    cout << " cannot be here. " << endl;
	    break;
    }
    g();
}

void g(){ throw 47;}

void my_except(){
    cout << " unexpected exception thrown " << endl;
    exit(0);
}

int main(){
    set_unexpected(my_except);
    for(int i =1; i <= 3; i++)
	try{
	    f(i);
	}catch(Up){
	    cout << "Up catch." << endl;
	}catch(Fit){
	    cout << " Fit Cathc." << endl;
	}

}
