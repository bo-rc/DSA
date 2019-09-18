#include <vector>
#include <algorithm>
#include <iostream>

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v)
{
    for (const auto &x : v)
        out << x << ",";
    return out;
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<std::vector<T>> &vv)
{
    for (const auto &v : vv)
    {
        out << v;
        out << std::endl;
    }

    return out;
}

void all_states(int size, std::vector<std::vector<int>> &perm)
{
    std::vector<int> s(size, 0);
    perm.push_back(s); // all '0'

    for (int i = 0; i < s.size(); ++i)
    {
        s[i] = 1;
        std::vector<int> temp(s);
        std::sort(temp.begin(), temp.end());
        do
        {
            perm.push_back(temp);
        } while (std::next_permutation(temp.begin(), temp.end()));
    }
}

std::vector<std::vector<int>> stl_all_state(size_t n)
{
    std::vector<std::vector<int>> ret;

    all_states(n, ret);

    return ret;
}

void dfs(size_t n, size_t s, std::vector<int> curr, std::vector<std::vector<int>> &perm)
{
    if (curr.size() == n)
    {
        perm.push_back(curr);
        return;
    }

    for (size_t i = s; i < n; ++i)
    {
        curr.push_back(0);
        dfs(n, i + 1, curr, perm);
        curr.pop_back();
        curr.push_back(1);
        dfs(n, i + 1, curr, perm);
        curr.pop_back();
    }
}

std::vector<std::vector<int>> dfs_all_state(size_t n)
{
    std::vector<std::vector<int>> ret;
    std::vector<int> curr;

    dfs(n, 0, curr, ret);

    return ret;
}

int main()
{
    auto v_dfs = dfs_all_state(3);
    auto v_stl = stl_all_state(3);

    std::cout << "dfs all states: \n";
    std::cout << v_dfs << std::endl;
    std::cout << "stl all states: \n";
    std::cout << v_stl << std::endl;

    return 0;
}