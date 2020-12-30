#         11       9
#      B ----> E -------
#    ^ |\4    ^         \
# 3 /  | \   /-4  5    1 \>
# A   4|  > D------> F ---> H
# 6 \  |  ^  \2             ^
#    \ > /8 11\>     2     /
#      > C ---> G --------/
#

# Longest path on weighted graph is generally NP-Hard
# but, for DAG, there is a linear solution:
# the trick is to use SSSP algorithm with all weights multiply by -1

# this algorithm is used to find the Critical Path in scheduling problems

from collections import namedtuple
import sys

Edge = namedtuple('Edge', 'node weight')

g = {
        'A': [Edge('B', 3), Edge('C', 6)],
        'B': [Edge('C', 4), Edge('D', 4), Edge('E', 11)],
        'C': [Edge('D', 8), Edge('G', 11)],
        'D': [Edge('E', -4), Edge('F', 5), Edge('G', 2)],
        'E': [Edge('H', 9)],
        'F': [Edge('H', 1)],
        'G': [Edge('H', 2)],
        'H': []
    }

gNodes = [node for node in g.keys()]

src = 'A'

topOrder = []
visited = {node : False for node in gNodes}
prev = {node : node for node in gNodes}
dist = {node : sys.maxsize for node in gNodes}
dist['A'] = 0

def dfs(node):
    visited[node] = True
    print("visited: ", node)
    for n in [ n.node for n in g[node]]:
        if not visited[n]:
            dfs(n)
    
    topOrder.append(node)

for node in gNodes:
    if not visited[node]:
        dfs(node)

topOrder = topOrder[::-1]
print("topological ordering: ", topOrder)

g_negative = {}

for key, edges in g.items():
    g_negative[key] = []
    for e in edges:
        g_negative[key].append(Edge(e.node, -e.weight))

for node in topOrder:
    for edge in g_negative[node]:
        # travel relaxing
        toNode = edge.node
        travel = dist[node] + edge.weight
        if travel < dist[toNode]:
            dist[toNode] = travel
            prev[toNode] = node

print("longest paths: ", prev)
longDists = {node : -d for node, d in dist.items()}
print("longest dists: ", longDists)