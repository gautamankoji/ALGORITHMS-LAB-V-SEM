# EX 05: Find optimal solution for a Knapsack problem

The Knapsack Problem is a classic optimization problem where you aim to maximize the total value of items you can carry in a knapsack with a fixed weight capacity. Here’s an outline of the optimal solution using dynamic programming.

### Problem Definition

Given:

- A list of items, each with a weight and a value.
- A knapsack with a maximum weight capacity.

Objective: Maximize the total value of the items in the knapsack without exceeding the weight capacity.

### Dynamic Programming Approach

1. **Create a DP Table**:
   - Create a 2D array `dp` where `dp[i][w]` represents the maximum value that can be achieved with the first `i` items and a maximum weight capacity of `w`.

2. **Initialization**:
   - If there are no items or the capacity is zero, the maximum value is zero: `dp[0][w] = 0` and `dp[i][0] = 0`.

3. **Filling the DP Table**:
   - Iterate through each item and each weight capacity.
   - For each item, decide whether to include it in the knapsack or not:
     - If including the item, update the value based on the remaining capacity.
     - If not including the item, keep the previous value.

4. **Return the Result**:
   - The result will be in `dp[n][W]`, where `n` is the total number of items and `W` is the maximum weight capacity.

### Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

int main() {
    int W = 50;
    vector<int> weights = {10, 20, 30};
    vector<int> values = {60, 100, 120};
    int n = values.size();
    int maxValue = knapsack(W, weights, values, n);
    cout << "Maximum value in the Knapsack = " << maxValue << endl;
    return 0;
}
```

### Output

```bash
Maximum value in the Knapsack = 220
```

### Explanation

- The `knapsack` function builds a DP table where each entry `dp[i][w]` contains the maximum value obtainable with the first `i` items and weight limit `w`.
- It iterates through each item and checks if including it increases the maximum value without exceeding the weight limit.
- Finally, the maximum value obtainable with all items and the given weight capacity is returned, demonstrating the optimal solution to the Knapsack Problem.
