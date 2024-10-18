# EX 12: Implement N-Queen’s problem

The **N-Queens Problem** is a classic combinatorial problem where the objective is to place N queens on an N×N chessboard such that no two queens threaten each other. This means that no two queens can be in the same row, column, or diagonal.

### Algorithm (Backtracking Approach)

1. **Recursive Function**: Use backtracking to place queens on the board.
2. **Base Case**: If all queens are placed (i.e., the current row equals N), print the solution.
3. **Placement Logic**: For each row, try placing a queen in each column and check if the position is safe.
4. **Safety Check**: Ensure that no other queen is in the same column or diagonal.
5. **Backtrack**: If placing a queen leads to a solution, continue; otherwise, remove the queen and try the next column.

### Code Implementation

Here’s a C++ implementation of the N-Queens problem using backtracking:

```cpp
#include <iostream>
#include <vector>

using namespace std;

bool isSafe(const vector<vector<int>>& board, int row, int col, int N) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) return false;  
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;  
    }
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) return false;  
    }
    return true;  
}

bool solveNQueens(vector<vector<int>>& board, int row, int N) {
    if (row == N) {
        
        return true;
    }
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;         
            if (solveNQueens(board, row + 1, N)) {
                return true;  
            }
            board[row][col] = 0;
        }
    }
    return false;  
}

void printSolution(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row) {
            cout << (cell ? " Q " : " . ");  
        }
        cout << endl;
    }
}

int main() {
    int N = 4;  
    vector<vector<int>> board(N, vector<int>(N, 0));  
    if (solveNQueens(board, 0, N)) {
        printSolution(board);  
    } else {
        cout << "No solution exists!" << endl;
    }
    return 0;
}
```

### Output

```bash
.  Q  .  . 
.  .  .  Q
Q  .  .  .
.  .  Q  .
```

### Explanation

- **Initialization**: The chessboard is represented as a 2D vector initialized with zeros (0 means an empty cell).
- **isSafe Function**: This function checks whether it is safe to place a queen at a specific position by checking the column and both diagonals for other queens.
- **solveNQueens Function**:
  - This recursive function attempts to place a queen in each column of the current row. If placing the queen leads to a solution, it continues; otherwise, it backtracks by removing the queen.
  - The base case is when all queens have been placed successfully.
- **printSolution Function**: This function prints the chessboard with queens represented by `Q` and empty cells by `.`.
- **Main Function**: Sets the board size (N) and initiates the solving process. If a solution is found, it is printed; otherwise, it indicates that no solution exists.

### Complexity

- **Time Complexity**: The time complexity is \(O(N!)\) in the worst case, as we might have to explore all permutations of queen placements.
- **Space Complexity**: The space complexity is \(O(N^2)\) due to the storage of the chessboard.

This implementation effectively finds a solution to the N-Queens problem using a backtracking approach. Adjust the value of N in the main function to test different board sizes.
