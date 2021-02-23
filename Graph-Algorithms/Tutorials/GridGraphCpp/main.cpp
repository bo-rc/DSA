#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <queue>
#include <algorithm>

const std::vector<std::string> maze {
    "S...*",
    "***..",
    "E...."
}; 
struct Cell {
    int row;
    int col;
};

void debug_print (const std::vector<std::vector<bool>>& visited)
{
    std::cout << std::boolalpha;
    for (const auto& row : visited)
    {
        for (const auto& cell : row)
            std::cout << cell << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void debug_print (std::vector<std::vector<Cell>>& prev)
{
    for (const auto& row : prev)
    {
        for (const auto& cell : row)
        {
            std::cout << std::setw(8) << "(" << cell.row << "," << cell.col << ") ";
        }
        std::cout << std::endl;  
    }
    std::cout << std::endl;
}

struct MazeExits {
    Cell src;
    Cell exit;
};

MazeExits findSourceExit(const std::vector<std::string>& maze)
{  
    int src_row,  src_col, exit_row, exit_col;
    
    for (size_t r = 0; r < maze.size(); ++r)
    {
        for (size_t c = 0; c < maze[0].size(); ++c )
        {
            if (maze[r][c] == 'S')
            {
                src_row = r;
                src_col = c;
            }
            else if (maze[r][c] == 'E')
            {
                exit_row = r;
                exit_col = c;
            }
        }
    }
    return {{src_row, src_col}, {exit_row, exit_col}};
}

int main()
{        
    auto mazeExits = findSourceExit(maze);

    int src_row{mazeExits.src.row};
    int src_col{mazeExits.src.col};
    int exit_row{mazeExits.exit.row};
    int exit_col{mazeExits.exit.col};

    // Setup BFS grid search
    std::vector<int> dir_row {-1, +1,  0,  0};
    std::vector<int> dir_col { 0,  0, -1, +1};

    std::vector<std::vector<bool>> visited(maze.size(), std::vector<bool>(maze[0].size(), false));
    std::vector<std::vector<Cell>> prev(maze.size(), std::vector<Cell>(maze[0].size(), {-1, -1}));

    std::queue<int> rowQueue;
    rowQueue.push(src_row);
    std::queue<int> colQueue;
    colQueue.push(src_col);
    visited[src_row][src_col] = true;

    bool pathFound = false;
    while (not rowQueue.empty())
    {
        int row = rowQueue.front();
        int col = colQueue.front();
        rowQueue.pop();
        colQueue.pop();
  
        // explore neighborhood of (row, col)
        for (size_t i = 0; i < 4; ++i)
        {
            int rr = row + dir_row[i];
            int cc = col + dir_col[i];

            if (rr < 0 or cc < 0 or rr >= maze.size() or cc >= maze[0].size())
            {
                continue;
            }

            if (visited[rr][cc])
            {
                continue;
            }

            if (maze[rr][cc] == '*')
            {
                continue;
            }

            rowQueue.push(rr);
            colQueue.push(cc);
            visited[rr][cc] = true;
            prev[rr][cc] = {row, col};

            // early termination
            if (maze[rr][cc] == 'E')
            {
                pathFound = true;
                break;
            }
        }
    }
    
    std::cout << "print the final prev" << std::endl;
    debug_print(prev);
    std::vector<Cell> path;
    if (pathFound)
    {
        while (true) {

            path.push_back({exit_row, exit_col});
            auto prev_row = prev[exit_row][exit_col].row;
            auto prev_col = prev[exit_row][exit_col].col;
            auto prevCell = maze[prev_row][prev_col];

            if (prevCell == 'S') {
                break;
            }

            exit_row = prev_row;
            exit_col = prev_col;
        }

        path.push_back({src_row, src_col});

        std::reverse(path.begin(), path.end());

        for (const auto& cell : path)
        {
            std::cout << "(" << cell.row << "," << cell.col << ") ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "trapped!" << std::endl;
    }

    return 0;
}