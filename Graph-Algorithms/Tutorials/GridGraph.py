# Grids are a form of implicit graph
# we can transform grid to graph using adj. list/matrix,
# but for grid problems, there is a better technique: 
#  
#  direction vectors for exploration:
#
#         | north:  |
#         | (r-1,c) |
# ________|_________|________
# west:   |         |east:
# (r, c-1)|  (r,c)  |(r, c+1)
# ________|_________|________
#         | south:  |
#         | (r+1,c) |
#         |         |
#
# for this grid, direction vector is:
# dr = [-1, +1, 0, 0]
# dc = [0, 0, +1, -1]
#
#
# // Define the direction vectors for
# // north, south, east and west.
# dr = [—1, +1, 0, 0]
# dc = [ 0, 0, +1, —1]
# for(i = 0; i < 4; i++):
#     rr = r + dr[i]
#     cc = c + dc[i]
#     # Skip invalid cells. Assume R and
#     # C for the number of rows and columns
#     if rr < 0 or cc < 0: continue
#     if rr >= R or cc >= C: continue
#     #(rr, cc) is a neighbouring cell of (r, c)
#

# Another trick:
# use one queue for each dimension to avoid packing/unpacking dimensions

# Dungeon Problem:

from queue import Queue
from collections import deque

# Find the shortest path from S to E,
# if it exits. 
#
# The maze:
#
# S . . . .
# * * . * .
# . . . . .
# * * . . *
# E . . . *
#
maze = [
        ['S', '.', '.', '.', '.'],
        ['*', '*', '.', '*', '.'],
        ['*', '*', '.', '.', '.'],
        ['*', '*', '*', '.', '*'],
        ['E', '.', '.', '.', '*'],
    ]

for i in range(len(maze)):
    for j in range(len(maze[0])):
        if maze[i][j] == 'S':
            srcRow = i
            srcCol = j
        elif maze[i][j] == 'E':
            exitRow = i
            exitCol = j

# setup maintainance and tools
visited = [[False] * 5 for i in range(5)]
prev = [[None] * 5 for i in range(5)]

directionVectorRow = [-1, +1, 0, 0]
directionVectorCol = [ 0, 0, +1, -1]

# use separate queues for row and col to 
# ease data packing and unpacking
rowQueue = Queue()
colQueue = Queue()
rowQueue.put(srcRow)
colQueue.put(srcCol)
visited[srcRow][srcCol] = True
reached = False

# BFS traversal
while not rowQueue.empty():
    r = rowQueue.get()
    c = colQueue.get()

    if maze[r][c] == 'E':
        reached = True
        break

    # explore neibhbours:
    for i in range(4):
        rr = r + directionVectorRow[i]
        cc = c + directionVectorCol[i]

        # print("explore: ", (rr, cc))

        if rr < 0 or rr >= len(maze) or cc < 0 or cc >= len(maze[0]):
            continue
        if visited[rr][cc]:
            continue
        if maze[rr][cc] == '*':
            continue

        rowQueue.put(rr)
        colQueue.put(cc)
        visited[rr][cc] = True
        # print("visited: ", (rr, cc))
        prev[rr][cc] = (r, c)
    
if reached:
    path = []
    while prev[exitRow][exitCol] != None:
        path.append((exitRow, exitCol))
        pr, pc = prev[exitRow][exitCol]
        exitRow, exitCol = pr, pc
    path = path[::-1]
    print("takes ", len(path), " steps:")
    print(path)
else:
    print("trapped!")
