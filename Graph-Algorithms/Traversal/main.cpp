#include "traversal.h"
#include <iostream>

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

    std::cout << "built graph: \n";
    g.print();

    std::cout << "dfs:\n";
    traversal(g, dfs);
    std::cout << "bfs:\n";
    traversal(g, bfs);
}