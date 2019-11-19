#include <iostream>
#include <string>
#include <typeinfo>

template <typename T, int row, int col>
class Matrix
{
public:
    void id() const
    {
        std::cout << "type: " << typeid(T).name() << std::endl;
    }
};

template <>
void Matrix<int, 3, 3>::id() const
{
    std::cout << "int type" << std::endl;
}

int main(int argc, char **argv)
{
    Matrix<float, 4, 4> fMat;
    fMat.id();
    Matrix<int, 3, 3> myMat;
    myMat.id();
    return 0;
}