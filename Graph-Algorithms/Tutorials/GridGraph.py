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

rq = Queue()
cq = Queue()

# S . . . .
# * * . * .
# . . . . .
# * * . . *
# E . . . *
m = [
        ['S', '.', '.', '.', '.'],
        ['*', '*', '.', '*', '.'],
        ['*', '*', '.', '.', '.'],
        ['*', '*', '*', '.', '*'],
        ['*', '.', '.', 'E', '*'],
    ]

for i in range(len(m)):
    for j in range(len(m[0])):
        if m[i][j] == 'S':
            sr = i
            sc = j
        elif m[i][j] == 'E':
            er = i
            ec = j

# some setup
visited = [[False] * 5 for i in range(5)]
prev = [[None] * 5 for i in range(5)]

dr = [-1, +1, 0, 0]
dc = [ 0, 0, +1, -1]

# init
reached = False
rq.put(sr)
cq.put(sc)
visited[sr][sc] = True

while not rq.empty():
    r = rq.get()
    c = cq.get()

    if m[r][c] == 'E':
        reached = True
        break

    # explore neibhbours:
    for i in range(4):
        rr = r + dr[i]
        cc = c + dc[i]

        print("explore: ", (rr, cc))

        if rr < 0 or rr >= len(m) or cc < 0 or cc >= len(m[0]):
            continue
        if visited[rr][cc]:
            continue
        if m[rr][cc] == '*':
            continue

        rq.put(rr)
        cq.put(cc)
        visited[rr][cc] = True
        print("visited: ", (rr, cc))
        prev[rr][cc] = (r, c)
    
if reached:
    count = 0
    path = deque()
    while prev[er][ec] != None:
        path.appendleft((er, ec))
        pr, pc = prev[er][ec]
        er, ec = pr, pc
        count += 1
    print("takes ", count, " steps:")
    print(path)
else:
    print("trapped!")


