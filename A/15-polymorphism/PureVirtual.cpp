#include <iostream>

using namespace std;

class Pet{
public:
    virtual void speak() const = 0;
    virtual void eat() const = 0;
    
};

void Pet::eat() const{
    cout << " Pet::eat() " << endl;
}

void Pet::speak() const{
    cout << " Pet :: speak() " << endl;
}

class Dog: public Pet{
public:
    void speak() const { Pet::speak(); }
    void eat() const { Pet::eat(); }
};

int main()
{
    Dog simba;
    simba.speak();
    simba.eat();
}
