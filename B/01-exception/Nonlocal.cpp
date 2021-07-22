#include <iostream>

using namespace std;

class RainBow{
public:
    RainBow(){ cout << " RainBow() " << endl;}
    ~RainBow(){ cout << " ~RainBow() " << endl;}
};

void oz(){
    RainBow r;
    for(int i =0; i < 3; i++)
	cout << " there's no place like home " << endl;
    throw 47;
}

int main(){
    try{
	cout << " tonado , swith, munchins... " << endl;
	oz();
    }catch(int){
	cout << " ant em ! i had the strangest dream..." << endl;
    }
}
