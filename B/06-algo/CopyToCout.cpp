#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>

using namespace std;

bool gt5(int x){ return 5 < x; }

int main(){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9 ,10};
    const size_t SIZE = sizeof a / sizeof a[0];
    remove_copy_if(a, a + SIZE, ostream_iterator<int>(cout, "\n"), gt5);
}
