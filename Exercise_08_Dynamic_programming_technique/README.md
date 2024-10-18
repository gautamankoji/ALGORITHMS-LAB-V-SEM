# EX 08: Implement 0/1 Knapsack problem

The 0/1 Knapsack Problem is a classic optimization problem that aims to determine the maximum value that can be carried in a knapsack of limited capacity, given a set of items with specific weights and values. In the 0/1 Knapsack problem, each item can either be included (1) or excluded (0) from the knapsack.

### Algorithm

1. **Define the Problem**: Let `n` be the number of items, `W` be the capacity of the knapsack, and `wt[]` and `val[]` be arrays representing the weights and values of the items, respectively.
2. **Create a DP Table**: Use a 2D array `dp[n+1][W+1]` where `dp[i][w]` will store the maximum value that can be obtained using the first `i` items with a maximum weight of `w`.
3. **Base Case**: Initialize `dp[0][w]` to 0 for all `w`, since no items mean no value.
4. **Fill the DP Table**:
   - For each item `i` (from 1 to `n`):
     - For each weight `w` (from 1 to `W`):
       - If the weight of the current item `wt[i-1]` is less than or equal to `w`, update `dp[i][w]` as the maximum of including or excluding the item.
       - Otherwise, inherit the value from the previous item.
5. **Result**: The maximum value will be stored in `dp[n][W]`.

### Code Implementation

Here's a C++ implementation of the 0/1 Knapsack problem using dynamic programming:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int W, const vector<int>& wt, const vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

int main() {
    int W = 50;
    vector<int> wt = {10, 20, 30};
    vector<int> val = {60, 100, 120};
    int n = val.size();
    int maxValue = knapsack(W, wt, val, n);
    cout << "Maximum value in Knapsack: " << maxValue << endl;
    return 0;
}
```

### Output

```bash
Maximum value in Knapsack: 220
```

### Explanation

- **Function Signature**: The `knapsack` function takes the maximum weight `W`, vectors of weights `wt` and values `val`, and the number of items `n`.
- **DP Table Creation**: A 2D vector `dp` is created to store maximum values. It's initialized to 0, which signifies that no value is obtained when no items are considered.
- **Filling the DP Table**:
  - For each item, the algorithm checks if it can fit in the current weight limit.
  - If it can fit, the maximum value is computed as the greater of including or excluding the item.
  - If it cannot fit, it retains the previous maximum value without the item.
- **Final Result**: The maximum value obtainable within the knapsack's capacity is printed, which is stored in `dp[n][W]`.

This dynamic programming approach ensures an efficient solution to the 0/1 Knapsack problem with a time complexity of \(O(n \cdot W)\) and space complexity of \(O(n \cdot W)\).
