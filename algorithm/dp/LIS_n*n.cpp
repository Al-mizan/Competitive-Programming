#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int> &arr) {
    int n = arr.size();
    
    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int length = LIS(arr);
    cout << "Length of the Longest Increasing Subsequence is: " << length << endl;

    return 0;
}
