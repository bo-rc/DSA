#include "Dijkstra.h"
#include <algorithm>
#include <limits>

// This works but not the classical nor the better solution
// keep this just for comparison purposes
// see below a more efficient classical implementation
void Dijkstra2(const Graph &g, int s, std::vector<int> &dist, std::vector<int> &prev)
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

    // this algorithm pushes all nodes to the heap bucket
    // see below an alternative which deals with nodes reached 
    // (because unreached nodes have infinite cost right now: no need to look at).
    for (size_t i = 0; i < dist.size(); ++i)
    {
        heap.emplace_back(i, dist[i]);
    }

    std::make_heap(begin(heap), end(heap), comp);

    // loop until empty
    // This algorithm does not push nodes to bucket from this step on.
    while (!heap.empty())
    {
        // this node must be the shortest so far
        std::pop_heap(begin(heap), end(heap), comp);
        auto front = heap.back();
        heap.pop_back();

        auto u = front.first;

        // this ensures we update known nodes only
        for (auto &e : g.get_edges(u))
        {
            vID v = e.to;
            long travel = dist[u] + e.weight;

            // find a shorter path to v, update v
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

void Dijkstra(const Graph &g, int s, std::vector<int> &dist, std::vector<int> &prev)
{
    // 1. initialization ->
    auto n = g.get_vsize();
    dist.assign(n, std::numeric_limits<int>::max());
    prev.assign(n, -1);

    dist[s] = 0;
    prev[s] = s;
    // <- initialization

    // 2. init a priority queue: the frontier bucket->
    using vID = int;
    using cost = int;
    std::vector<std::pair<vID, cost>> heap;
    auto comp = [](std::pair<vID, cost> p1, std::pair<vID, cost> p2) { return p1.second > p2.second; };


    heap.emplace_back(s, 0);
    // deal with the frontier only
    // i.e. nodes who are connected. 
    for (const auto& e : g.get_edges(s))
    {
        heap.emplace_back(e.to, e.weight);
    }

    std::make_heap(begin(heap), end(heap), comp);
    // <- init a priority queue bucket

    // 3. loop until empty
    while (!heap.empty())
    {
        // 3.1 pop the lowest cost node u ->
        std::pop_heap(begin(heap), end(heap), comp);
        auto front = heap.back();
        heap.pop_back();
        auto u = front.first;
        // <- pop the lowest cost node u

        // 3.2 expand frontier, adjust cost if necessary ->
        for (auto &e : g.get_edges(u))
        {
            vID v = e.to;
            long travel = dist[u] + e.weight;

            if (travel < dist[v]) // this means v is a newly discovered node
            {
                dist[v] = travel;
                prev[v] = u;

                heap.emplace_back(v, dist[v]);

                // adjust queue, move the shortest to front
                std::make_heap(begin(heap), end(heap), comp);
            }
        }
        // <- adjust cost in bucket based on known information
        // all nodes are processed once and only once because: no negative edges assumed.
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