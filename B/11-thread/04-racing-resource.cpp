#include <iostream>
#include <thread>
#include <mutex>

std::mutex mu;

void shared_count(std::string msg, int id)
{
    mu.lock();
    std::cout << msg << ":" << id << std::endl;
    mu.unlock();
}

void thread_function()
{
    for(int i = -100; i < 0; i++)
        shared_count("thread function",i);
}

int main()
{
    std::thread t(&thread_function);
    for(int i = 0 ; i < 100; i++)
        shared_count("main function",i);
    t.join();
}
