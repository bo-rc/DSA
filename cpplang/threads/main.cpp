#include <thread>
#include <iostream>

int main()
{
    std::thread t = std::thread([&]() {
        std::cout << std::thread::hardware_concurrency() << "  " << std::endl
                  << t.get_id() << std::endl;
    });

    t.join();

    return 0;
}