#include <vector>
#include <algorithm>
#include <iostream>
#include <thread>

int main()
{
    std::vector<std::thread> workers;
    for(int i =0; i < 5; i++){
        workers.push_back(std::thread([i]()
        {
            std::cout <<"[" << i <<  "]inner:  thread function\n";
        }));
    }
    std::cout << " OUTER: thread function\n";
    std::for_each(workers.begin(), workers.end(),[](std::thread &t)
    {
        t.join();
    });
}
