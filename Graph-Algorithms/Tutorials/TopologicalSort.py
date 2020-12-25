# Topological sort:

# Trees are DAG so there is always a topsort:
# picking off leafs until there is no node left.

# DAG: use DFS

# g:
#     0      6
#    ^      ^
#   /  \   /  \
#       >      >
#  1 ->  2  ->  5       7
#        ^       \     /
#        |        > 8 <
#        3 
#        ^
#         \
#          4    9 -> 10
#               ^               
#               |
#              11

from collections import deque

g = {
     0: [2], 1: [0, 2], 2: [5, 6], 3: [2], 4: [3], 
     5: [8], 6: [5], 7: [8], 8: [], 
     9 : [10], 10:[], 11:[9]
    }

n = len(g)

visited = [False] * n
order = deque()

def dfs(node):
    global g, visited, order
    visited[node] = True
    print("visited: ", node)

    for neighbor in g[node]:
        if not visited[neighbor]:
            dfs(neighbor)
    
    order.appendleft(node)

for i in range(n):
    if not visited[i]:
        dfs(i)

print(order)


