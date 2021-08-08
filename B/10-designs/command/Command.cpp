#include <iostream>
#include <vector>

using namespace std;

class Command{
public:
    virtual void execute() = 0;
};

class Hello : public Command {
public:
    void execute() {cout << " Hello " ; }
};

class World : public Command{
public:
    void execute() { cout << "World" ; }
};

class Iam : public Command{
public:
    void execute() { cout << " I am the command pattern " ; }
};

class Macro{
    vector<Command*> commands;
public:
    void add(Command* c) { commands.push_back(c);}
    void run(){
        vector<Command*>::iterator it = commands.begin();
        while(it != commands.end())
            (*it++)->execute();
    }
};

int main(){
    Macro macro;
    macro.add(new Hello);
    macro.add(new World);
    macro.add(new Iam);
    macro.run();
    cout << endl;
}
