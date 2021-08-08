#include <iostream>
#include <thread>

int main()
{
    std::thread t([](){
        std::cout << " thread function \n";
    });

    std::cout << " Main thread. \n";

    t.join();


}
