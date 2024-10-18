# EX 10: Implement traveling salesperson problem

The Traveling Salesperson Problem (TSP) is a classic optimization problem that aims to find the shortest possible route that visits a set of cities exactly once and returns to the origin city. The problem is NP-hard, meaning no polynomial-time solution is known. A common approach to solve it is using dynamic programming with bit masking.

### Algorithm (Dynamic Programming with Bitmasking)

1. **State Representation**:
   - Define `dp[mask][i]` as the minimum cost to visit the cities represented by `mask`, ending at city `i`.
   - `mask` is a bitmask where the `j`-th bit is set if city `j` has been visited.

2. **Initialization**:
   - Set `dp[1][0] = 0` since starting at city 0 incurs no cost.
   - All other `dp[mask][i]` values should be initialized to infinity.

3. **Recurrence Relation**:
   - For each state `mask` and each city `i`, iterate over all possible cities `j` that can be visited:
     - Update `dp[mask][i]` as follows:
       \[
       dp[mask][i] = \min(dp[mask][i], dp[mask \setminus (1 << i)][j] + cost[j][i])
       \]
   - This checks if the best path to `i` from a previously visited city `j` can be improved.

4. **Final Computation**:
   - The final result can be computed by returning to the starting city:
     \[
     \text{result} = \min(dp[(1 << n) - 1][i] + cost[i][0]) \text{ for all } i
     \]

### Code Implementation

Here’s a C++ implementation of the TSP using dynamic programming and bitmasking:

```cpp
#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
using namespace std;

const int INF = numeric_limits<int>::max();

int tsp(int mask, int pos, const vector<vector<int>>& cost, vector<vector<int>>& dp) {
    if (mask == (1 << cost.size()) - 1) {
        return cost[pos][0];
    }
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }
    int answer = INF;
    for (int city = 0; city < cost.size(); city++) {
        if ((mask & (1 << city)) == 0) {
            int newAnswer = cost[pos][city] + tsp(mask | (1 << city), city, cost, dp);
            answer = min(answer, newAnswer);
        }
    }
    return dp[mask][pos] = answer;
}

int main() {
    vector<vector<int>> cost = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    int n = cost.size();
    vector<vector<int>> dp(1 << n, vector<int>(n, -1));
    int minCost = tsp(1, 0, cost, dp);
    cout << "Minimum cost of the Traveling Salesperson Problem: " << minCost << endl;
    return 0;
}
```

### Output

```bash
Minimum cost of the Traveling Salesperson Problem: 80
```

### Explanation

- **Initialization**: The cost matrix is defined, where `cost[i][j]` represents the distance between city `i` and city `j`.
- **Dynamic Programming Function**: The `tsp` function uses recursion with memoization (caching results in `dp`) to avoid recalculating results for the same state.
  - The base case checks if all cities have been visited (`mask == (1 << n) - 1`). If so, it returns to the starting city.
  - For each unvisited city, it calculates the cost of traveling to that city and recurses with the updated mask.
- **Final Result**: The minimum cost to complete the tour is printed.

This implementation effectively solves the TSP using dynamic programming with bitmasking, achieving a time complexity of \(O(n^2 \cdot 2^n)\), which is feasible for small values of \(n\) (up to around 20).
