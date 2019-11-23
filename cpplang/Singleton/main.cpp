#include <iostream>
#include <thread>
#include <mutex>

/* classical singleton pattern */
class MySingleton
{

private:
    static MySingleton *instance;
    MySingleton() = default;
    ~MySingleton() = default;

public:
    MySingleton(const MySingleton &) = delete;
    MySingleton &operator=(const MySingleton &) = delete;

    static MySingleton *getInstance() // use static otherwise not thread-safe
    {
        if (!instance)
        {
            instance = new MySingleton();
        }
        return instance;
    }
};

MySingleton *MySingleton::instance = nullptr;
/* classical singleton pattern */

/* using call_once */
class MySingleton2
{

private:
    static MySingleton2 *instance;
    MySingleton2() = default;
    ~MySingleton2() = default;
    static std::once_flag f;

public:
    MySingleton2(const MySingleton2 &) = delete;
    MySingleton2 &operator=(const MySingleton2 &) = delete;

    static MySingleton2 *getInstance() // use static otherwise not thread-safe
    {
        std::call_once(f, initSingleton);
        return instance;
    }

    static void initSingleton()
    {
        instance = new MySingleton2();
    }
};

std::mutex mtx;

void func()
{
    // std::lock_guard<std::mutex> lock(mtx);
    std::cout << "MySingleton::getInstance(): " << MySingleton::getInstance() << std::endl;
}

int main()
{

    std::cout << std::endl;

    std::thread t1 = std::thread(func);
    std::thread t2 = std::thread(func);
    t1.join();
    t2.join();

    std::cout << std::endl;
}