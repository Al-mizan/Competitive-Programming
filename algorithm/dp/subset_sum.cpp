#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(vector<int> &arr, int sum) {
    int n = arr.size();
    vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
    
    for (int i = 0; i <= n; i++)
        dp[i][0] = true; // If sum is 0, then answer is true (empty subset)
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < arr[i-1]) dp[i][j] = dp[i-1][j]; 
            else dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
        }
    }
    return dp[n][sum];
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int sum;
    cin >> sum;

    if (isSubsetSum(arr, sum))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
