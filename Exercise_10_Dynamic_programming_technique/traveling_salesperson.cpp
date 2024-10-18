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