#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;  // for amount 0 minimum coins also required 0 and this is Base case

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return (dp[amount] == INT_MAX) ? -1 : dp[amount];
}

int main() {
    int n, amount;
    cin >> n;
    
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    cin >> amount;

    int result = coinChange(coins, amount);
    if (result == -1) {
        cout << "It is not possible to make the amount with the given coins." << endl;
    }
    else {
        cout << "Minimum number of coins required: " << result << endl;
    }

    return 0;
}
