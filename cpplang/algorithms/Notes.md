# Permutation

```cpp
#include <algorithm>

std::set<std::string> all_perm(std::string str)
{
    std::set<std::string> permSet;

    do
    {
        permSet.insert(str);
    } while (std::next_permutation(str.begin(), str.end())); // at most N/2 swaps per call

    return permSet;
}
```
* `std::is_permutation`

# Binary divide
Use `middle = start + (end — start) / 2` instead of `middle = (start + end) / 2` to avoid integer overflow

# Top 'K' elements
Use a heap to maintain top 'K':
```cpp
std::vector<int> topK(K);
...
std::make_heap(begin(topK), end(topK));
...
topK.push_back(21);
std::push_heap(begin(topK), end(topK));
std::pop_heap(begin(topK), end(topK));
// topK still has top K
```

# K-way merge
Use a heap of K elements to track top elements from K sorted arrays.


