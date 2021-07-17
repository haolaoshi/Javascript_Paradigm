#include <iostream>

#define SBUFSIZE    100 

using namespace std;


const int buf_size = 100;
char buffer[buf_size];
extern const int bsize;

const int i[] = {1,2,3,4};
int main()
{
    
    cout << "type a char  & CR " ;
    const char c = cin.get();
    const char c2 = c + '1';
    cout << c2;

    cout << i[2];
}
