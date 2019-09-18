#pragma once

#include <vector>
#include <string>

enum struct vertex_state
{
    UNEXPLORED,
    VISITED
};
enum struct edge_state
{
    UNEXPLORED,
    VISITED,
    CROSS /* indicates a cycle */
};

class Graph
{
public:
    struct Vertex
    {
        int id;
        int val;
        std::string label;

        Vertex(int new_id, int new_val, std::string new_label) : id(new_id), val(new_val), label(new_label) {}
    };

    struct Edge
    {
        int from;
        int to;
        int weight;

        Edge(int new_from, int new_to, int new_weight) : from(new_from), to(new_to), weight(new_weight) {}
    };

    Graph() : m_isDG(false) {}
    Graph(bool isDG) : m_isDG(isDG) {}

    bool add_vertex(int value = 0, std::string label = "");
    bool add_edge(int u, int v, int w);

    size_t get_vsize() const;

    std::vector<Edge> get_edges(int u) const;
    std::vector<Edge> get_all_edges() const;
    std::vector<Vertex> get_all_vertices() const;
    std::vector<int> get_adjacent(int u) const;

    Graph::Vertex &operator[](int i);
    Graph::Vertex operator[](int i) const;

    bool is_dGraph() const { return m_isDG; };

    void print() const;

private:
    bool m_isDG = false;
    std::vector<Vertex> m_vertices;
    std::vector<std::vector<Edge>> m_edges;
};