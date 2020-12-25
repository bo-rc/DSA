# graph traversal
# finding connected components

# g:
#    0       6
#   / \     / \
#  1 - 2 - 5   7
#      |    \ /
#      3     8
#       \
#        4    9 - 10
#              \
#               11

from queue import Queue

g = {
     0: [1, 2], 1: [0, 2], 2: [0, 1, 3, 5], 3: [2, 4], 4: [3], 
     5: [2, 6, 8], 6: [5, 7], 7: [6, 8], 8: [5, 7], 
     9 : [10,11], 10:[9], 11:[9]
    }

n = len(g)

visited = [False] * n
components = [-1] * n
group = 0

def dfs(at):
    global visited, components, group
    visited[at] = True
    print("visit: ", at)
    components[at] = group
    
    for neigbor in g[at]:
        if not visited[neigbor]:
            dfs(neigbor)

def bfs_iterative(source):
    global visited, components, group
    qu = Queue()

    # init qu
    qu.put(source)
    visited[source] = True
    components[source] = group

    # iterative traversal
    while not qu.empty():
        top = qu.get()

        for neighbor in g[top]:
            if not visited[neighbor]:
                qu.put(neighbor)
                visited[neighbor] = True
                components[neighbor] = group
                print("visit: ", neighbor)

def bfs_recursive(source):
    global visited, components, group

    # init qu
    qu = Queue()
    qu.put(source)
    visited[source] = True
    components[source] = group

    _bfs_recursive(source, qu)

def _bfs_recursive(source, qu):
    global visited, components, group

    while not qu.empty():
        top = qu.get()

        for neighbor in g[top]:
            if not visited[neighbor]:
                qu.put(neighbor)
                visited[neighbor] = True
                components[neighbor] = group
                print("visit: ", neighbor)
        _bfs_recursive(top, qu)

def find_components(graph, traversal_func=dfs):
    global visited, components, group
    for i in range(len(graph)):
        if not visited[i]:
            traversal_func(i)
            group += 1
    
    return group, components

print(find_components(g, bfs_iterative))