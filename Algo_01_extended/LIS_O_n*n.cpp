#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the length of the longest increasing subsequence
int LIS(vector<int> &arr) {
    int n = arr.size();
    
    // dp[i] will store the length of the LIS ending at index i
    vector<int> dp(n, 1);

    // Fill dp array using dynamic programming approach
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    // The maximum value in dp[] is the length of the LIS
    return *max_element(dp.begin(), dp.end());
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the LIS function and output the result
    int length = LIS(arr);
    cout << "Length of the Longest Increasing Subsequence is: " << length << endl;

    return 0;
}
