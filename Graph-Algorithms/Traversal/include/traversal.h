#pragma once

#include "Graph.h"
#include <vector>

void dfs(const Graph &g, int s, std::vector<vertex_state> &v_status);

void bfs(const Graph &g, int s, std::vector<vertex_state> &v_status);

void traversal(const Graph &g, decltype(dfs) trav);