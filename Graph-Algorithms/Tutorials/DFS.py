g = {0: [1, 2], 1: [0, 2], 2: [0, 1, 3], 3: [2, 4], 3: [2, 4], 4: [3], 5: [2, 6, 8], 6: [5, 7], 7: [6, 8], 8: [5, 7]}
n = len(g)

visited = [False] * n
components = [-1] * n
group = 0

def find_components(graph):
    global visited
    global components
    global group
    for i in range(len(graph)):
        if not visited[i]:
            dfs(i)
            group += 1
    
    return group, components

def dfs(at):
    global visited
    global components
    global group
    visited[at] = True
    components[at] = group
    
    for neigbor in g[at]:
        if not visited[neigbor]:
            dfs(neigbor)

print(find_components(g))