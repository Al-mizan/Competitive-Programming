#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);  // Create a DP array of size (amount + 1)
    dp[0] = 0;  // Base case: 0 coins are needed to make amount 0

    // Fill the DP array
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    // If dp[amount] is still INT_MAX, it means we can't make the amount
    return (dp[amount] == INT_MAX) ? -1 : dp[amount];
}

int main() {
    int n, amount;
    cout << "Enter the number of coin denominations: ";
    cin >> n;
    
    vector<int> coins(n);
    cout << "Enter the coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << "Enter the amount: ";
    cin >> amount;

    int result = coinChange(coins, amount);
    if (result == -1) {
        cout << "It is not possible to make the amount with the given coins." << endl;
    } else {
        cout << "Minimum number of coins required: " << result << endl;
    }

    return 0;
}
