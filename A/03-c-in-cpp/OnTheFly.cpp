#include <iostream>


using namespace std;

int main()
{
    int q = 0;

    while((char c = q) != 'q')
    {
	q = cin.get();
	cout << c << endl;

    }
    return 0;
}
