#include <vector>
#include <list>
#include <deque>
#include <iostream>

using namespace std;


class Shape{
public:
    virtual void draw() = 0;
    virtual ~Shape(){};
};

class Circle : public Shape{
public:
    void draw(){ cout << "Circle draw: " << endl; }
    ~Circle(){ cout  << " ~Circle " << endl; }
};

class Triangle : public Shape{
public:
    void draw(){ cout << " Triangle draw: " << endl; }
    ~Triangle(){ cout << " ~Triangle " << endl; }
};

class Square : public Shape {
public:
    void draw(){ cout << " Square draw: " << endl; }
    ~Square(){ cout << " ~Square " << endl; }
};

int main()
{
    //typedef std::vector<Shape*> Container;
    //typedef std::list<Shape*> Container;
    typedef std::deque<Shape*> Container;
    typedef Container::iterator Iter;
    
    Container shapes;
    shapes.push_back(new Circle);
    shapes.push_back(new Triangle);
    shapes.push_back(new Square);

    shapes.push_back(new Circle);
    for(Iter i = shapes.begin(); i != shapes.end(); i++)
        (*i)->draw();
    for(Iter i = shapes.begin(); i != shapes.end(); i++)
        delete *i;
}
