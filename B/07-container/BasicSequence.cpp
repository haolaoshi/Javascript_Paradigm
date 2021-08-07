#include <deque>
#include <iostream>
#include <vector>
#include <list>


using namespace std;

template<typename Container>
void print(Container& c,char* tile= ""){
    cout << title << ':' << endl;

    if(c.empty()){
        cout << " (tempty) " << endl;
        return ;
    }

    typename Container::iterator it;
    for(it = c.begin(); it != c.end(); it++){
        cout << *it << " ";
    }

    cout << endl;
    cout << "size() "   << c.size()
        << " max_size() " << c.max_size()
        << " front()  "   << c.front()
        << " back()  "    << c.back()
        << endl;
}

template<typename ContainerOfInt> void basicOps(char* s){
    cout << " ------- " << s << " ------- " << endl;
    
}
