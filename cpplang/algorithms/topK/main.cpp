#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <functional>

int main()
{
    constexpr size_t K = 10;
    std::vector<int> topK(K);

    auto randomNumberBetween = [](int low, int high) {
        auto randomFunc = [distribution_ = std::uniform_int_distribution<int>(low, high),
                           random_engine_ = std::mt19937{std::random_device{}()}]() mutable {
            return distribution_(random_engine_);
        };
        return randomFunc;
    };

    std::generate(std::begin(topK), std::end(topK), randomNumberBetween(1, 10));
    std::for_each(std::begin(topK), std::end(topK), [](int a) { std::cout << a << ",";} );
    std::cout << std::endl;

    std::make_heap(std::begin(topK), std::end(topK), std::greater<>{});
    
    topK.push_back(21);
    std::push_heap(std::begin(topK), std::end(topK), std::greater<>{});
    std::pop_heap(std::begin(topK), std::end(topK), std::greater<>{});
    topK.pop_back();

    std::for_each(std::begin(topK), std::end(topK), [](int a) { std::cout << a << ",";} );

    return 0;
}