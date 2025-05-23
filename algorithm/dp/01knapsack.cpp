#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, vector<int> &weights, vector<int> &values, int n) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for (int i=1; i<=n; i++) {
        for (int w=0; w<=W; w++) {
            if (weights[i-1] <= w) {
                dp[i][w] = max(dp[i-1][w], values[i-1] + dp[i-1][w-weights[i-1]]);
            }
            else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[n][W];
}

int main() {
    int n, W;
    cin >> n >> W;

    vector<int> values(n), weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    cout << knapsack(W, weights, values, n) << endl;

    return 0;
}
