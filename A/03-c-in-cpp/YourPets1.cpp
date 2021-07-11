#include <iostream>

using namespace std;

int fun(int &r)
{
    cout << "&r = " << &r << endl;
    r += 100;
    return 0;
}

char*  boo()
{
    char* str = "hello";
    cout << " &str = " << &str<<endl;
    return str;
}
int arr[10];


int main()
{
    int i  = 0;
    int b[3]={'o','k','\0'};    
    
    cout <<"&i="<<&i<<endl;
    cout <<"&b[]="<<&b<<endl;
    cout <<"&arr[]="<<&arr<<endl;
    fun(i);
    cout <<"i = " << i << endl;
    cout <<"&fun = "<<&fun<<endl;
    char *t = boo();

    cout <<"&t = " << &t <<endl;
    cout <<"&boo = "<<&boo<<endl;
    return 0;
}
