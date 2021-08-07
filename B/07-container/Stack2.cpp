#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <list>
#include <cstddef>

using namespace std;

template<class STK>
void stackOut(STK& s,ostream& os = cout){
    while(!s.empty()){
        os << s.top() << "\n";
        s.pop();
    }
}

class Line{
    string line;
    size_t lspaces;

public:
    Line(string s) : line(s){
        lspaces = line.find_first_not_of(' ');
        if(lspaces == string::npos)
            lspaces = 0;
        line = line.substr(lspaces);
    }
    friend ostream& operator<<(ostream& os,const Line& l){
        for(size_t i =0; i < l.lspaces; i++)
            os << ' ';
        return os << l.line;
    }
    void changeWidth(size_t w){
        cout << lspaces << endl; 
        lspaces /= 4 ;  // 16 -- 4x4 
        lspaces  *= w;  // 32 -- 4x8 
    }
};

int main(int argc, char* argv[]){

    ifstream in("Stack2.cpp");
    list<Line> lines;

    string s;
    while(getline(in,s))
        lines.push_front(s);
     
    stack<Line,list<Line> > stk(lines);
    stackOut(stk);

}
