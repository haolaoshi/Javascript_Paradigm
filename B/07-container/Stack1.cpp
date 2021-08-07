#include <fstream>
#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <string>

using namespace std;

typedef stack<string,list<string> > Stack1;
//typedef stack<string,vector<string> > Stack1;
//typedef stack<string> Stack1;

int main(){
    ifstream in("Stack1.cpp");
    Stack1  test_lines;
    string line;

    while(getline(in,line))
        test_lines.push(line + "\n");

    while(!test_lines.empty()){
        cout << test_lines.top();
        test_lines.pop();
    }
}
