#include <iostream>
#include <typeinfo>

#define INFO std::cout << "-> " << typeid(*this).name() << "  " << __PRETTY_FUNCTION__ << std::endl;
#define FUNC_INFO std::cout << __PRETTY_FUNCTION__ << std::endl;
struct Pose
{
    float x;

    Pose(){INFO} Pose(const float f) : x{f} { INFO }

    ~Pose() { INFO }
};

struct Can_convert2Pose
{
    float x;
    operator Pose() const
    {
        return Pose{x};
    }
};

void func(const Pose &other)
{
    FUNC_INFO;
    std::cout << "pretend to do some work: " << other.x << std::endl;
}

/**
 * perfect forwarding: avoids temporaries
 *  Try to comment out this section, 
 *  you will see more lines as output (i.e. unnecessary work done)
 */
template <typename T>
void func(T &&other)
{
    FUNC_INFO;

    auto p = std::forward<T>(other);
    std::cout << "pretend to do some work: " << p.x << std::endl;
}

int main(int argc, char **argv)
{
    Can_convert2Pose p1{};
    // binds to lvalue no problem
    func(p1);
    // binds to rvalue no problem
    func(Can_convert2Pose{1.0});
}