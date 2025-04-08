#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, vector<int> &weights, vector<int> &values, int n) {
    vector<int> dp(W+1, 0);

    for (int i=0; i<n; i++) {
        for (int w=W; w>=weights[i]; w--) {
            dp[w] = max(dp[w], values[i] + dp[w-weights[i]]);
        }
    }

    return dp[W];
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
