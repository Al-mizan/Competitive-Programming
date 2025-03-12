#include <iostream>
#include <vector>
using namespace std;

// Function to check if there's a subset with a given sum
bool isSubsetSum(vector<int>& set, int n, int sum) {
    // Create a 2D dp array where dp[i][j] will be true if there is a subset
    // of set[0..i-1] with sum equal to j
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    // If sum is 0, the answer is true (empty subset always works)
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    // If sum is not 0 and set is empty, the answer is false
    for (int i = 1; i <= sum; i++) {
        dp[0][i] = false;
    }

    // Fill the dp table using a bottom-up approach
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            // If the current element is greater than the sum, we can't include it
            if (set[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                // Else, we either include the element or exclude it
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
            }
        }
    }

    // dp[n][sum] will be true if there is a subset with the given sum
    return dp[n][sum];
}

int main() {
    int n, sum;

    cout << "Enter the number of elements in the set: ";
    cin >> n;

    vector<int> set(n);
    cout << "Enter the elements of the set: ";
    for (int i = 0; i < n; i++) {
        cin >> set[i];
    }

    cout << "Enter the target sum: ";
    cin >> sum;

    // Call the isSubsetSum function and output the result
    if (isSubsetSum(set, n, sum)) {
        cout << "There exists a subset with the given sum." << endl;
    } else {
        cout << "No subset with the given sum exists." << endl;
    }

    return 0;
}
