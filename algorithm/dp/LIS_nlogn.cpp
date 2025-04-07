#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the Longest Increasing Subsequence
int LIS(vector<int>& nums) {
    vector<int> dp;

    for(int i=0; i<nums.size(); i++) {
        auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
        if(it == dp.end()) dp.push_back(nums[i]);
        else *it = nums[i];
    }

    return dp.size();
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
