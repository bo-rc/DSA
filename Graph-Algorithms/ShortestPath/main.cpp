#include "Dijkstra.h"
#include "BFS.h"
#include "Graph.h"
#include <iostream>

using namespace std;

void print_results(const vector<int> &dist_D, const vector<int> &prev_D, int start)
{
    for (int i = 0; i < dist_D.size(); ++i)
    {
        cout << "distance from: " << start << " to: " << i << " : " << dist_D[i] << endl;
    }

    cout << endl;

    for (int i = 0; i < prev_D.size(); ++i)
    {
        int dest = i;
        cout << endl;
        cout << "path from: " << start << " to: " << dest << ": \n";
        while (dest != start)
        {
            cout << dest << " <- ";
            dest = prev_D[dest];
            if (dest == -1)
            {
                cout << endl;
                cout << "cannot reached from: " << start << endl;
                break;
            }
        }

        if (dest == start)
        {
            cout << start << "[done]";
        }
    }
    cout << endl;
}
void test_dijkstra(const Graph &g, int start)
{
    cout << "**************** Dijkstra starts **************** " << endl;

    vector<int> dist_D;
    vector<int> prev_D;

    Dijkstra(g, start, dist_D, prev_D);
    print_results(dist_D, prev_D, start);
    cout << "**************** Dijkstra ends **************** " << endl;
}

void test_dijkstra_heap(const Graph &g, int start)
{
    cout << "**************** Dijkstra_heap starts **************** " << endl;

    vector<int> dist_D;
    vector<int> prev_D;

    Dijkstra_heap(g, start, dist_D, prev_D);
    print_results(dist_D, prev_D, start);
    cout << "**************** Dijkstra_heap ends **************** " << endl;
}

void test_DFS(const Graph &g, int start)
{
    cout << "**************** BFS starts **************** " << endl;

    vector<int> dist_D;
    vector<int> prev_D;

    BFS(g, start, dist_D, prev_D);
    print_results(dist_D, prev_D, start);
    cout << "**************** BFS ends **************** " << endl;
}

int main()
{
    Graph g;
    g.add_vertex(1, "S");
    g.add_vertex(1, "A");
    g.add_vertex(1, "B");
    g.add_vertex(1, "C");
    g.add_vertex(1, "D");
    g.add_vertex(1, "E");

    g.add_edge(0, 1, 1);
    g.add_edge(0, 2, 1);
    g.add_edge(1, 4, 1);
    g.add_edge(4, 5, 1);
    g.add_edge(5, 3, 1);
    g.add_edge(5, 2, 1);
    g.add_edge(2, 3, 1);
    g.add_edge(0, 3, 1);

    g.print();

    test_DFS(g, 0);
    test_dijkstra(g, 0);
    test_dijkstra_heap(g, 0);

    int i = 1;
    while (--i > 0)
    {
        Graph g2;
        g2.add_vertex(0, "A");
        g2.add_vertex(1, "B");
        g2.add_vertex(2, "C");
        g2.add_vertex(3, "D");
        g2.add_vertex(4, "D");
        g2.add_vertex(5, "D");
        g2.add_vertex(6, "F");
        g2.add_edge(0, 1, 1);
        g2.add_edge(0, 2, 1);
        g2.add_edge(1, 2, 1);
        g2.add_edge(2, 5, 1);
        g2.add_edge(1, 3, 1);
        g2.add_edge(3, 5, 1);
        g2.add_edge(4, 3, 1);
        g2.add_edge(5, 4, 1);

        g2.print();
        test_DFS(g2, 2);
        test_dijkstra(g2, 2);
        test_dijkstra_heap(g2, 2);
    }

    return 0;
}
