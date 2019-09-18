#include "traversal.h"
#include <stack>
#include <queue>
#include <iostream>

void dfs(const Graph &g, int s, std::vector<vertex_state> &v_status)
{
    std::stack<int> stage;
    std::vector<int> v_pushed(v_status.size(), false);
    stage.push(s);
    v_pushed[s] = true;

    while (not stage.empty())
    {
        auto u = stage.top();
        stage.pop();

        std::cout << g[u].label << ",";
        v_status[u] = vertex_state::VISITED;

        for (const auto &v : g.get_adjacent(u))
        {
            if (v_status[v] == vertex_state::UNEXPLORED && not v_pushed[v])
            {
                stage.push(v);
                v_pushed[v] = true;
            }
        }
    }
}

void bfs(const Graph &g, int s, std::vector<vertex_state> &v_status)
{
    std::queue<int> stage;
    std::vector<bool> v_pushed(v_status.size(), false);
    stage.push(s);
    v_pushed[s] = true;

    while (not stage.empty())
    {
        auto u = stage.front();
        stage.pop();

        std::cout << g[u].label << ",";
        v_status[u] = vertex_state::VISITED;

        for (const auto &v : g.get_adjacent(u))
        {
            if (v_status[v] == vertex_state::UNEXPLORED && not v_pushed[v])
            {
                stage.push(v);
                v_pushed[v] = true;
            }
        }
    }
}

void traversal(const Graph &g, decltype(dfs) trav)
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