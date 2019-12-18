#include <thread>
#include <iostream>
#include <vector>

int main()
{
    std::vector<std::thread> ts;
    for (int i = 0; i < std::thread::hardware_concurrency(); ++i)
    {
        std::thread t = std::thread([&]() {
            std::cout << i << ": "
                      << t.get_id() << std::endl;
        });
        ts.push_back(std::move(t));
    }

    for (auto &t : ts)
        t.join();

    return 0;
}