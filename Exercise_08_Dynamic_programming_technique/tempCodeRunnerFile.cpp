#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve the 0/1 Knapsack problem
int knapsack(int W, const vector<int>& wt, const vector<int>& val, int n) {
    // Create a 2D DP array
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];  // The maximum value that can be obtained
}

int main() {
    int W = 50;  // Capacity of the knapsack
    vector<int> wt = {10, 20, 30};  // Weights of items
    vector<int> val = {60, 100, 120};  // Values of items
    int n = val.size();  // Number of items

    int maxValue = knapsack(W, wt, val, n);

    cout << "Maximum value in Knapsack: " << maxValue << endl;

    return 0;
}
