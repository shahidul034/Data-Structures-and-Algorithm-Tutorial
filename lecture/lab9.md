### **Backtracking Tutorial**

#### **What is Backtracking?**
Backtracking is a general algorithmic approach where we build a solution incrementally and abandon it (backtrack) as soon as we determine it cannot lead to a valid solution.

#### **General Steps in Backtracking:**
1. **Choose**: Make a choice or decision.
2. **Explore**: Proceed recursively to check if this choice leads to a solution.
3. **Unchoose**: If the choice does not lead to a solution, undo it and try another possibility.

---

### **Example: Solving a Maze Problem**
We will solve a maze where:
- `1` represents open paths.
- `0` represents walls.
- Start at the top-left corner `(0, 0)`.
- End at the bottom-right corner `(N-1, N-1)`.

#### **Steps:**
1. Use a recursive function to explore paths.
2. Use backtracking to discard paths that do not lead to the solution.
3. Mark visited cells to avoid revisiting.

---
### **Direction Mapping**
```cpp
int newX = x + dx[i];
int newY = y + dy[i];
```
| `i` | `dx[i]` | `dy[i]` | Movement Direction |
|-----|---------|---------|--------------------|
|  0  |    1    |    0    | Down               |
|  1  |    0    |    1    | Right              |
|  2  |   -1    |    0    | Up                 |
|  3  |    0    |   -1    | Left               |

### **Components of the Condition**
```cpp
(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && visited[x][y] == 0)
```
#### 1. **`x >= 0 && x < N`**
   - Ensures that the **row index `x`** is within bounds:
     - `x >= 0`: The row index is not negative (stays within the top boundary of the grid).
     - `x < N`: The row index is less than `N` (stays within the bottom boundary of the grid).
   - Together, these ensure that the move does not go outside the grid vertically.

#### 2. **`y >= 0 && y < N`**
   - Ensures that the **column index `y`** is within bounds:
     - `y >= 0`: The column index is not negative (stays within the left boundary of the grid).
     - `y < N`: The column index is less than `N` (stays within the right boundary of the grid).
   - Together, these ensure that the move does not go outside the grid horizontally.

#### 3. **`maze[x][y] == 1`**
   - Checks whether the cell `(x, y)` is a **valid path** in the maze:
     - If `maze[x][y] == 1`, the cell is open and can be moved into.
     - If `maze[x][y] == 0`, the cell is a wall or obstacle, and the move is blocked.

#### 4. **`visited[x][y] == 0`**
   - Ensures that the cell `(x, y)` has **not been visited** yet:
     - `visited[x][y] == 0`: The cell has not been visited, so we can explore it.
     - `visited[x][y] == 1`: The cell has already been visited, so revisiting it would create unnecessary loops.

---
#### **C++ Code Implementation**

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Function to check if the current cell is valid to move
bool isValid(int x, int y, const vector<vector<int>> &maze, const vector<vector<int>> &visited, int N) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && visited[x][y] == 0);
}

// Backtracking function to solve the maze
bool solveMaze(int x, int y, vector<vector<int>> &maze, vector<vector<int>> &solution, vector<vector<int>> &visited, int N) {
    // Base case: Reached the destination
    if (x == N - 1 && y == N - 1) {
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
    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (isValid(nextX, nextY, maze, visited, N)) {
            if (solveMaze(nextX, nextY, maze, solution, visited, N)) {
                return true;
            }
        }
    }

    // Backtrack: Unmark the current cell
    solution[x][y] = 0;
    visited[x][y] = 0;
    return false;
}

int main() {
    // Define the maze (1 = open path, 0 = wall)
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    int N = maze.size();

    // Solution and visited matrices
    vector<vector<int>> solution(N, vector<int>(N, 0));
    vector<vector<int>> visited(N, vector<int>(N, 0));

    // Solve the maze
    if (solveMaze(0, 0, maze, solution, visited, N)) {
        cout << "Solution exists:" << endl;
        for (const auto &row : solution) {
            for (int cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
```

---

[Full code](https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial/blob/main/code/backtracking.cpp)

#### **Explanation of the Code**
1. **`isValid` Function**:
   - Checks if the next move is within bounds, the cell is not a wall, and it hasn't been visited.

2. **`solveMaze` Function**:
   - Recursive function to explore paths.
   - Marks the current cell as part of the solution path.
   - Tries moving in all four directions (down, right, up, left).
   - Backtracks by unmarking the cell if the path does not lead to the solution.

3. **Base Case**:
   - When the destination `(N-1, N-1)` is reached, the solution is complete.

4. **Input Maze**:
   - The maze is hardcoded in this example, but you can take it as input from the user.

5. **Output**:
   - If a solution exists, it prints the solution path.
   - If no solution exists, it displays an appropriate message.

---

#### **Example Output**
For the given maze:
```
1 0 0 0
1 1 0 1
0 1 0 0
1 1 1 1
```
The solution is:
```
1 0 0 0
1 1 0 0
0 1 0 0
0 1 1 1
```

---

This example demonstrates the principles of backtracking and can be extended to other problems like the **N-Queens**, **Sudoku Solver**, or **Word Search**. Let me know if you'd like more examples or explanations!