#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

const std::vector<std::string> maze {
    "S...*",
    "***..",
    "E...."
}; 

void print_visited (const std::vector<std::vector<bool>>& visited)
{
    for (const auto& row : visited)
    {
        for (const auto& cell : row)
            std::cout << cell << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void print_prev (const std::vector<std::vector<std::vector<int>>>& prev)
{
    for (const auto& row : prev)
    {
        for (const auto& cell : row)
        {
            std::cout << "(";
            for (const auto& index : cell)
                std::cout << index << ",";
            std::cout <<") ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main()
{    
    // find S and E
    int src_row, src_col, exit_row, exit_col;

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

    std::cout << "source: (" << src_row << "," << src_col << ")" << std::endl;
    std::cout << "exit: (" << exit_row << "," << exit_col << ")" << std::endl;

    // Setup BFS grid search
    std::vector<int> dir_row {-1, +1,  0,  0};
    std::vector<int> dir_col { 0,  0, -1, +1};

    std::queue<int> rowQueue;
    std::queue<int> colQueue;

    std::vector<std::vector<bool>> visited;
    visited.resize(maze.size());

    for (auto & row : visited)
    {
        row.resize(maze[0].size(), false);
    }

    std::vector<std::vector<std::vector<int>>> prev;
    prev.resize(maze.size());

    for (auto & row : prev)
    {
        row.resize(maze[0].size());
        for (auto& cell : row)
        {
            cell.push_back(-1);
            cell.push_back(-1);
        }
    }

    rowQueue.push(src_row);
    colQueue.push(src_col);
    visited[src_row][src_col] = true;

    std::cout << " before BFS: " << std::endl;
    std::cout << " visited: " << std::endl;
    print_visited(visited);

    std::cout << " prev: " << std::endl;
    print_prev(prev);

    // BFS on maze graph
    bool pathFound = false;
    while (not rowQueue.empty())
    {
        int row = rowQueue.front();
        rowQueue.pop();
        int col = colQueue.front();
        colQueue.pop();

        std::cout << "pop: " << row << "," << col << std::endl;

        std::cout << " visited: " << std::endl;
        print_visited(visited);

        std::cout << " prev: " << std::endl;
        print_prev(prev);

        // explore neighborhood of (row, col)
        for (size_t i = 0; i < 4; ++i)
        {
            int rr = row + dir_row[i];
            int cc = col + dir_col[i];

            if (rr < 0 or cc < 0 or rr >= maze.size() or cc >= maze[0].size())
            {
                std::cout << "continue due to out bound rr = " << rr <<", cc =" << cc << std::endl;
                continue;
            }

            if (visited[rr][cc])
            {
                std::cout << "continue due to visited rr = " << rr <<", cc =" << cc << std::endl;
                continue;
            }

            if (maze[rr][cc] == '*')
            {
                std::cout << "continue due to blocked rr = " << rr <<", cc =" << cc << std::endl;
                continue;
            }

            std::cout << "exploring: (" << rr << ", " << cc << ")" << std::endl;

            rowQueue.push(rr);
            colQueue.push(cc);
            std::cout << "push: " << rr << "," << cc << std::endl;
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

    std::vector<std::vector<int>> path;

    std::cout << "print the final prev" << std::endl;
    print_prev(prev);
    if (pathFound)
    {
        int rr {exit_row};
        int cc {exit_col}; // current row and col index
        
        while (maze[rr][cc] != 'S')
        {
            std::cout << rr << "," << cc << " prev: " << prev[rr][cc][0] << "," << prev[rr][cc][1] << std::endl;
            std::vector<int> cell {rr, cc};
            path.push_back(cell);
            rr = prev[rr][cc][0];
            cc = prev[rr][cc][1];
        }

        std::cout << path.size() << " steps: " << std::endl;
        std::reverse(path.begin(), path.end());
        
        for (const auto& cell : path)
        {
            std::cout << "(";
            for (const auto& index: cell)
            {
                std::cout << index << ",";
            }
            std::cout << "), ";
        }
    }
    else
    {
        std::cout << "trapped!" << std::endl;
    }

    return 0;
}