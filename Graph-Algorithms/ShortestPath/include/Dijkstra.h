#pragma once

#include <vector>
#include "Graph.h"
#include "Heap.hpp"

void Dijkstra(const Graph &g, int s, std::vector<int> &dist, std::vector<int> &prev);
void Dijkstra_heap(const Graph &g, int s, std::vector<int> &dist, std::vector<int> &prev);