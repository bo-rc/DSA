#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <functional>

using namespace std;

struct Node {
    int from;
    int value;
};

int main()
{
    constexpr size_t K = 10;

    auto randomNumberBetween = [](int low, int high) {
        auto randomFunc = [distribution_ = std::uniform_int_distribution<int>(low, high),
                           random_engine_ = std::mt19937{std::random_device{}()}]() mutable {
            return distribution_(random_engine_);
        };
        return randomFunc;
    };

    std::vector<std::vector<int>> arr_10(10);
    
    for (auto & arr: arr_10)
    {
        std::generate_n(std::back_inserter(arr), 10, randomNumberBetween(0, 100));
        std::sort(std::begin(arr), std::end(arr));
    }

    std::vector<Node> kHeap(K);
    std::vector<int> sorted;
    for (int i = 0; i < K; ++i)
    {
        kHeap[i] = {i, arr_10[i][0]};
    }
    std::make_heap(std::begin(kHeap), std::end(kHeap), [](const Node& a, const Node& b) { return a.value < b.value; });

    return 0;
}