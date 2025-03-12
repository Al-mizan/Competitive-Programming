#include <iostream>
#include <vector>
using namespace std;

// Function to solve 0/1 Knapsack problem
int knapsack(int W, vector<int> &weights, vector<int> &values, int n) {
    // Create a 2D dp array where dp[i][w] stores the maximum value
    // that can be achieved with the first i items and a knapsack of capacity w
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Fill the dp array using dynamic programming
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w) {
                // If the weight of the ith item is less than or equal to the capacity w
                // then we can either take the item or leave it
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                // If the weight of the ith item is greater than the capacity w, we leave it
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // dp[n][W] contains the maximum value that can be achieved with n items and capacity W
    return dp[n][W];
}

int main() {
    int n, W;

    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> values(n), weights(n);
    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    // Call the knapsack function and output the result
    int max_value = knapsack(W, weights, values, n);
    cout << "Maximum value that can be carried in the knapsack: " << max_value << endl;

    return 0;
}
