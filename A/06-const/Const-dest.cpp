#include <iostream>


using namespace std;


class Tree{
    int height;
public:
    Tree(int initialize);
    ~Tree();
    void grow(int years);
    void printsize();
};

Tree::Tree(int he)
{
    cout << "Constuctor ... " << endl;
    height = he;
}

Tree::~Tree()
{
    cout <<"Inside tree destr."<<endl;
    printsize();
}

void Tree::grow(int years)
{
    height += years;
}

void Tree::printsize()
{
    cout <<"Tree height is " << height << endl;
}

int main()
{
    cout << "Before opening brace" << endl;
    {
	Tree t(12);
	cout << " after tree create " << endl;
	t.printsize();
	t.grow(20);
	cout << " before closing .. " << endl;
    }
    cout << "After closing brace" << endl;

}
