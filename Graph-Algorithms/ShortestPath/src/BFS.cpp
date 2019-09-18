#include "BFS.h"
#include <algorithm>
#include <limits>
#include <queue>
#include <set>
#include <iostream>

void BFS(const Graph &g, int s, std::vector<int> &dist, std::vector<int> &prev)
{
    // initialize result

    auto n = g.get_vsize();
    dist.assign(n, std::numeric_limits<int>::max());
    prev.assign(n, -1);
    dist[s] = 0;
    prev[s] = s;

    // useful temp containers
    std::queue<int> q;
    std::set<int> visited;

    // BFS starts here
    q.push(s);
    visited.insert(s);
    while (not q.empty())
    {
        int t = q.front();
        q.pop();

        std::vector<int> t_neighbors = g.get_adjacent(t);
        for (const auto &v : t_neighbors)
        {
            if (visited.find(v) == visited.end())
            {
                q.push(v);
                visited.insert(v);
                // update
                dist[v] = dist[t] + 1;
                prev[v] = t;
            }
        }
    }
}