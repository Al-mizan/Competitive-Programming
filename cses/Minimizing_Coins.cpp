#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll coinChange(vector<ll>& coins, ll amount) {
    vector<ll> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0 && dp[i-coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i-coin] + 1);
            }
        }
    }
    return (dp[amount] == INT_MAX) ? -1 : dp[amount];
}

int main() {
    ll n, amount;
    cin >> n >> amount;
    
    vector<ll> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    cout << coinChange(coins, amount) << endl;

    return 0;
}
