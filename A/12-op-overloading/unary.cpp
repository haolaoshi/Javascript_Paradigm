#include <iostream>

using namespace std;

class Integer{
    long i;
    Integer* This(){ return this; }

public:
    Integer(long ll = 0 ) : i(ll){}
    friend const Integer& 
	operator+(const Integer& a);
    friend const Integer
	operator-(const Integer& a);
    friend const Integer
	operator~(const Integer& a);
    friend Integer*
	operator&(const Integer& a);
   friend int
	operator!(const Integer& a);
    friend const Integer&
	operator++(Integer& a);
    friend const Integer
	operator++(Integer& a, int);
    friend const Integer&
	operator--(Integer& a);
    friend const Integer
	operator--(Integer& a, int);
};

const Integer& operator+(const Integer& a){
    cout << " +Integer \n";
    return a;
}

const Integer operator-(const Integer& a){
    cout << " -Integer \n";
    return Integer(-a.i);
}

const Integer  operator~(const Integer& a){
    cout << " ~Integer\n";
    return Integer(~a.i);
}
Integer* operator&(const Integer& a){
    cout << " operator& \n";
    return a.This();
}

int operator!(const Integer& a){
    cout << " opeator ! \n";
    return !a.i;
}

const Integer& operator++(Integer& a){
    cout << " ++operator \n";
    a.i++;
    return a;
}

const Integer operator++(Integer& a,int){
    cout<< " Operator++ \n";
    Integer before(a.i);
    a.i++;
    return before;
}

const Integer& operator--(Integer &a){
    cout << " operator-- \n";
    a.i--;
    return a;
}

const Integer operator--(Integer& a, int){
    cout << " --opeator  \n";
    Integer before(a);
    a.i--;
    return before;
}

void f(Integer a)
{
    +a;
    -a;
    ~a;
    Integer* p = &a;
    !a;
    ++a;
    a++;
    --a;
    a--;

}

class Byte{
    unsigned char b;
public:
    Byte(unsigned char bb = 0): b(bb){}
    const Byte& operator+() const{
	cout << " +Byte\n";
	return *this;
    }
    const Byte operator-() const{
	cout << "-Byte\n";
	return Byte(-b);
    }
    const Byte operator~() const{
	cout << " ~Byte\n";
	return Byte(~b);
    }

    Byte operator!() const{
	cout << " !Byte \n";
	return Byte(!b);
    }

    Byte* operator&(){
	cout << " &Byte \n";
	return this;
    }

    const Byte& operator++(){
	cout << " Byte++ \n";
	b++;
	return *this;
    }
    const Byte operator++(int){
	cout << " ++Byte\n";
	Byte before(b);
	b++;
	return before;
    }
    const Byte& operator--(){
	cout << " Byte-- \n";
	--b;
	return *this;
    }

    const Byte operator--(int){
	cout << " --Byte \n";
	Byte before(b);
	b--;
	return before;
    }
};

void g(Byte b){
    +b;
    -b;
    ~b;
    !b;
    Byte* p = &b;
    ++b;
    --b;
    b++;
    b--;
}

int main()
{
    Integer a;
    f(a);
    Byte b;
    g(b);
}
