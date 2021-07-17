#include <string>
#include <iostream>
#include <cstring>

using namespace std;

class StringStack{
    static const int size = 100;
    const string* stack[size];
    int index;
public:
    StringStack();
    void push(const string* s);
    const string* pop();
};

StringStack::StringStack(): index(0){
    memset(stack,0,size * sizeof(string*));
}

void StringStack::push(const string* s){
    if(index < size)
	stack[index++] = s;
}

const string* StringStack::pop(){
    if(index > 0){
	const string* v = stack[--index];
	stack[index] = 0;
	return v;
    }
    return 0;
}

string iceCreame[] = {
    "praline & cream",
    "fujdeg ripple",
    "jamocha almond fuge",
    "wild mountain blackberre",
    "lemon swirl",
    "rockey road",
    "deep choolacte fudge"
};


const int icsz = sizeof iceCreame / sizeof * iceCreame;

int main()
{
    StringStack ss;
    for(int i = 0 ; i < icsz; i++)
	ss.push(&iceCreame[i]);
    const string* cp;
    while(( cp = ss.pop()) != 0 )
	cout << *cp << endl;
}
