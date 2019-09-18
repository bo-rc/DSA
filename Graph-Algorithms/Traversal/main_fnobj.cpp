#include "Graph.h"
#include <queue>
#include <stack>
#include <iostream>

void dfs(const Graph &g, int s, std::vector<vertex_state> &v_status);
void bfs(const Graph &g, int s, std::vector<vertex_state> &v_status);

class Trav
{
public:
    virtual void operator()(const Graph &g, int s, std::vector<vertex_state> &v_status) = 0;

protected:
    std::vector<bool> vPushed;
};

class DFS final : public Trav
{
    void operator()(const Graph &g, int s, std::vector<vertex_state> &v_status) override
    {
        std::stack<int> stack;
        vPushed.resize(v_status.size(), false);
        stack.push(s);
        vPushed[s] = true;

        while (not stack.empty())
        {
            auto u = stack.top();
            stack.pop();

            std::cout << g[u].label << ",";
            v_status[u] = vertex_state::VISITED;

            for (const auto &v : g.get_adjacent(u))
            {
                if (v_status[v] == vertex_state::UNEXPLORED && not vPushed[v])
                {
                    stack.push(v);
                    vPushed[v] = true;
                }
            }
        }
        vPushed.clear();
    }
};

class BFS final : public Trav
{
    void operator()(const Graph &g, int s, std::vector<vertex_state> &v_status) override
    {
        std::queue<int> queue;
        vPushed.resize(v_status.size(), false);
        queue.push(s);
        vPushed[s] = true;

        while (not queue.empty())
        {
            auto u = queue.front();
            queue.pop();

            std::cout << g[u].label << ",";
            v_status[u] = vertex_state::VISITED;

            for (const auto &v : g.get_adjacent(u))
            {
                if (v_status[v] == vertex_state::UNEXPLORED && not vPushed[v])
                {
                    queue.push(v);
                    vPushed[v] = true;
                }
            }
        }
        vPushed.clear();
    }
};

void traversal(const Graph &g, Trav &trav)
{
    std::vector<vertex_state> v_status(g.get_vsize(), vertex_state::UNEXPLORED);

    for (int i = 0; i < v_status.size(); ++i)
    {
        if (v_status[i] == vertex_state::UNEXPLORED)
        {
            std::cout << "island starting with " << i << ": \n";
            trav(g, i, v_status);
            std::cout << "\n";
        }
    }
    std::cout << "traversal done.\n";
}

int main()
{
    // test
    Graph g;
    g.add_vertex(1, "S");
    g.add_vertex(1, "A");
    g.add_vertex(1, "B");
    g.add_vertex(1, "C");
    g.add_vertex(1, "D");
    g.add_vertex(1, "E");

    g.add_edge(0, 1, 1);
    g.add_edge(0, 3, 1);
    g.add_edge(1, 2, 1);
    g.add_edge(1, 3, 1);
    g.add_edge(2, 4, 1);
    g.add_edge(3, 4, 1);
    g.add_edge(4, 5, 1);

    g.add_vertex(1, "F");
    g.add_vertex(1, "G");
    g.add_edge(6, 7, 1);

    g.print();

    std::cout << "dfs:\n";
    DFS dfs;
    traversal(g, dfs);
    std::cout << "bfs:\n";
    BFS bfs;
    traversal(g, bfs);
}