// Compiled with: g++ -Wall -std=c++14 -pthread

#include <algorithm> // STL
#include <iostream>
#include <vector>

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v)
{
    std::for_each(v.cbegin(), v.cend(), [&](T e) { out << e << " "; });

    out << std::endl;

    return out;
}

template <typename T>
std::ostream &operator<<(std::ostream &out,
                         const std::vector<std::vector<T>> &mat)
{
    std::for_each(mat.cbegin(), mat.cend(), [&](std::vector<T> e) { out << e; });
    return out;
}

// [1,2,3]
void dfs(const std::vector<int> &v, size_t start, size_t size,
         std::vector<int> curr, std::vector<std::vector<int>> &m)
{
    if (curr.size() == size)
    {
        m.push_back(curr);
        return;
    }

    for (size_t i = start; i < v.size(); ++i)
    {
        curr.push_back(v[i]);
        dfs(v, i + 1, size, curr, m);
        curr.pop_back();
    }
}

// [1,2,3]
void dfs_perm(const std::vector<int> &v, size_t start, size_t size,
              std::vector<bool> &status, std::vector<int> curr,
              std::vector<std::vector<int>> &m)
{
    if (curr.size() == size)
    {
        m.push_back(curr);
        return;
    }

    for (size_t i = start; i < v.size(); ++i)
    {
        if (not status[i])
        {
            curr.push_back(v[i]);
            status[i] = true;
            dfs_perm(v, 0, size, status, curr, m);
            curr.pop_back();
            status[i] = false;
        }
    }
}

// dfs2([1,2],0,2,mat): curr=[1] start=0
//  dfs2([1,2],1,2): curr[1,2] start=1

std::vector<std::vector<int>> allsubset(const std::vector<int> &v)
{
    std::vector<std::vector<int>> ret;
    std::vector<bool> status(v.size(), false);

    for (size_t s = 0; s <= v.size(); ++s)
    {
        std::vector<int> curr;
        dfs_perm(v, 0, s, status, curr, ret);
    }

    return ret;
}

int main()
{
    std::vector<int> v{1, 2, 3};
    auto mat = allsubset(v);
    std::cout << "start:\n";
    std::cout << mat;
    std::cout << "end\n";
    return 0;
}