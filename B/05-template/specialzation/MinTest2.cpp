#include <cstring>
#include <iostream>
using std::string;
using std::cout;
using std::endl;


template<class T> const T& min(const T& a,const T& b)
{
    cout << "func "<< endl;
    return (a < b) ? a : b;
}

template<>
const char* const& min<const char*>(const char* const& a,
            const char* const &b){
    cout << "speci-func"<< endl;
    return (strcmp(a,b) < 0) ? a : b;
}

int main()
{
    const char *s2 = "say \" Ni -!\"", *s1 = "knights who";
    cout << min(s1,s2) << endl;
    cout << min<>(s1,s2) << endl;
}
