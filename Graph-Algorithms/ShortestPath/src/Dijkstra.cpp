#include "Dijkstra.h"
#include <algorithm>
#include <limits>

void Dijkstra(const Graph &g, int s, std::vector<int> &dist, std::vector<int> &prev)
{
    auto n = g.get_vsize();

    dist.assign(n, std::numeric_limits<int>::max());
    prev.assign(n, -1);

    dist[s] = 0;
    prev[s] = s;

    using vID = int;
    using len = int;
    std::vector<std::pair<vID, len>> heap;
    auto comp = [](std::pair<vID, len> p1, std::pair<vID, len> p2) { return p1.second > p2.second; };

    for (size_t i = 0; i < dist.size(); ++i)
    {
        heap.emplace_back(i, dist[i]);
    }

    std::make_heap(begin(heap), end(heap), comp);

    while (!heap.empty())
    {
        std::pop_heap(begin(heap), end(heap), comp);
        auto front = heap.back();
        heap.pop_back();

        auto u = front.first;

        for (auto &e : g.get_edges(u))
        {
            vID v = e.to;
            long travel = dist[u] + e.weight;

            if (travel < dist[v])
            {
                dist[v] = travel;
                prev[v] = u;

                // decrease key
                for (size_t i = 0; i < heap.size(); ++i)
                {
                    if (heap[i].first == v)
                    {
                        heap[i].second = travel;
                        break;
                    }
                }

                std::make_heap(begin(heap), end(heap), comp);
            }
        }
    }
}

class Comp
{
public:
    bool operator()(const std::pair<int, int> &p1, const std::pair<int, int> &p2) const { return p1.second < p2.second; };
};

void Dijkstra_heap(const Graph &g, int s, std::vector<int> &dist, std::vector<int> &prev)
{
    auto n = g.get_vsize();

    dist.assign(n, std::numeric_limits<int>::max());
    prev.assign(n, -1);

    dist[s] = 0;
    prev[s] = s;

    using vID = int;
    using len = int;

    Heap<std::pair<vID, len>, Comp> heap;

    for (size_t i = 0; i < dist.size(); ++i)
    {
        heap.push({i, dist[i]});
    }

    while (!heap.empty())
    {
        auto front = heap.peek();
        heap.pop();

        auto u = front.first;

        for (auto &e : g.get_edges(u))
        {
            vID v = e.to;
            long travel = dist[u] + e.weight;

            if (travel < dist[v])
            {
                dist[v] = travel;
                prev[v] = u;

                // decrease key
                for (size_t i = 0; i < heap.size(); ++i)
                {
                    if (heap[i].first == v)
                    {
                        heap[i].second = travel;
                        heap.decrease_key(i);
                        break;
                    }
                }
            }
        }
    }
}