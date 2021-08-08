#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <cassert>

int main()
{
    std::vector<std::thread> workers;
    for(int i=0; i < 5; i++){
        auto t = std::thread([i]()
        {

            std::cout << " thread function: " << i << "\n";
        });
        workers.push_back(std::move(t));
    }

    std::cout << " main \n";

    std::for_each(workers.begin(), workers.end(), [](std::thread &t)
    {
        assert(t.joinable());
        t.join();
    });
}
/**If you're an experienced C++ programmer and are anything like me, you initially approached C++11 thinking, "Yes, yes, I get it. It's C++, only more so." But as you learned more, you were surprised by the scope of the changes. auto declarations, range-based for loops, lambda expressions, and rvalue references change the face of C++, to say nothing of the new concurrency features. And then there are the idiomatic changes. 0 and typedefs are out, nullptr and alias declarations are in. Enums should now be scoped. Smart pointers are now preferable to built-in ones. Moving objects is normally better than copying them. Effective Modern C++ by Scott Meyers    */
