#include "Graph.h"
#include <iostream>
#include <algorithm>
#include <iterator>

bool Graph::add_vertex(int value, std::string label)
{
    m_vertices.emplace_back(m_vertices.size(), value, label);
    m_edges.emplace_back(std::vector<Edge>{});
    return true;
}

bool Graph::add_edge(int from, int to, int w)
{
    if (from >= m_vertices.size() || to >= m_vertices.size())
        return false;

    for (auto v : get_adjacent(from))
    {
        if (to == v)
            return false;
    }

    m_edges[from].emplace_back(from, to, w);

    if (!m_isDG)
        m_edges[to].emplace_back(to, from, w);

    return true;
}

size_t Graph::get_vsize() const
{
    return m_vertices.size();
}

std::vector<Graph::Edge> Graph::get_edges(int u) const
{
    if (u >= m_vertices.size())
        return {};

    return m_edges[u];
}

std::vector<Graph::Edge> Graph::get_all_edges() const
{
    std::vector<Graph::Edge> ret;

    for (int i = 0; i < m_vertices.size(); ++i)
    {
        auto edges = get_edges(i);
        std::move(edges.begin(), edges.end(), std::back_inserter(ret));
    }

    return ret;
}

std::vector<Graph::Vertex> Graph::get_all_vertices() const
{
    return m_vertices;
}

std::vector<int> Graph::get_adjacent(int u) const
{
    std::vector<int> ret;
    std::for_each(m_edges[u].begin(), m_edges[u].end(),
                  [&](Graph::Edge e) {
                      ret.push_back(e.to);
                  });

    return ret;
}

Graph::Vertex &Graph::operator[](int i)
{
    return m_vertices[i];
}

Graph::Vertex Graph::operator[](int i) const
{
    return m_vertices[i];
}

// implemented for you
void Graph::print() const
{
    for (size_t i = 0; i < m_vertices.size(); ++i)
    {
        std::cout << i << "(" << m_vertices[i].label << ") : ";
        for (const auto &e : m_edges[i])
        {
            std::cout << "->"
                      << e.to << "(" << m_vertices[e.to].label << ")"
                      << ", ";
        }
        std::cout << std::endl;
    }
}
