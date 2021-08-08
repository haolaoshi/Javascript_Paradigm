#include <iostream>
#include <thread>

void thread_function()
{
    std::cout << " thread function \n";
}

int main()
{
    std::thread t(&thread_function);//starting thread
    std::cout << " main thread\n";
    t.detach();
    if(t.joinable())
        t.join();//waiting thread 
}
