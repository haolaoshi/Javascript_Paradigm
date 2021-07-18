#include <iostream>
#include "../require.h"

using namespace std;

char oneChar(const char* charArray = 0)
{
    static const char* s ;

    if(charArray){
	s = charArray;
	return *s;
    }

    require(s,"un-initialized s ");
    if(*s == '\0')
	return 0;
    return *s++;
}

char* a = "abcdefg";
int main()
{
    oneChar(a);
    char c;
    while(( c = oneChar()) != 0)
	cout << c << endl;
}
