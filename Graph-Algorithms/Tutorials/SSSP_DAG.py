#         11       9
#      B ----> E -------
#    ^ |\4    ^         \
# 3 /  | \   /-4  5    1 \>
# A   4|  > D------> F ---> H
# 6 \  |  ^  \2             ^
#    \ > /8 11\>     2     /
#      > C ---> G --------/
#

# using TopSort on DAG -> O(V+E)
# Shortest paths are always well-defined in DAG
# even if negative weights, no negative-weight cycles since acyclic
#
# after topSort, if there is a path from X to Y, X should precedes Y.
# ref: Cormen p.655
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

print("topological ordering: ", topOrder[::-1])


for node in topOrder[::-1]:
    for edge in g[node]:
        # travel relaxing
        toNode = edge.node
        travel = dist[node] + edge.weight
        if travel < dist[toNode]:
            dist[edge.node] = travel
            prev[toNode] = node

print("paths: ", prev)
print("dists: ", dist)