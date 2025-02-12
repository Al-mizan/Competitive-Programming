#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll maxSubarraySum(vector<ll>& arr) {
    ll maxSum = arr[0], currSum = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        currSum = max(arr[i], currSum + arr[i]);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    cout << maxSubarraySum(arr) << endl;

    return 0;
}
