#include <iostream>
#include <vector>
using namespace std;

// Function to check if the current cell is valid to move
bool isValid(int x, int y, const vector<vector<int>> &maze, const vector<vector<int>> &visited, int N)
{
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && visited[x][y] == 0);
}

// Backtracking function to solve the maze
bool solveMaze(int x, int y, vector<vector<int>> &maze, vector<vector<int>> &solution, vector<vector<int>> &visited, int N)
{
    // Base case: Reached the destination
    if (x == N - 1 && y == N - 1)
    {
        solution[x][y] = 1;
        return true;
    }

    // Mark the current cell as visited
    visited[x][y] = 1;
    solution[x][y] = 1;

    // Define movements in the four possible directions (down, right, up, left)
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    // Explore all possible directions
    for (int i = 0; i < 4; i++)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (isValid(nextX, nextY, maze, visited, N))
        {
            if (solveMaze(nextX, nextY, maze, solution, visited, N))
            {
                return true;
            }
        }
    }

    // Backtrack: Unmark the current cell
    solution[x][y] = 0;
    visited[x][y] = 0;
    return false;
}

int main()
{
    // Define the maze (1 = open path, 0 = wall)
    //vector<vector<int>> maze = {
    //    {1, 0, 0, 0},
    //   {1, 1, 0, 1},
    //   {0, 1, 0, 0},
    //  {1, 1, 1, 1}
    //};
    vector<vector<int>> maze =
    {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 0, 0, 0},
        {1, 1, 1, 1}
    };
    int N = maze.size();

    // Solution and visited matrices
    vector<vector<int>> solution(N, vector<int>(N, 0));
    vector<vector<int>> visited(N, vector<int>(N, 0));

    // Solve the maze
    if (solveMaze(0, 0, maze, solution, visited, N))
    {
        cout << "Solution exists:" << endl;
        for (const auto &row : solution)
        {
            for (int cell : row)
            {
                cout << cell << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists." << endl;
    }

    return 0;
}

