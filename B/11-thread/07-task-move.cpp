#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <cassert>

void task(int&  i)
{
    std::cout << "worker: " << i << "\n";
}

int main()
{
    std::vector<std::thread> workers;
    for(int i = 0 ; i < 5; i++){
        auto t = std::thread(&task,std::ref(i));
        workers.push_back(std::move(t));
    }

    std::cout << " main \n";
    std::for_each(workers.begin(),workers.end(),[](std::thread& t)
    {
        assert(t.joinable());
        t.join();
    });
}
