#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the Longest Common Subsequence (LCS)
int LCS(string X, string Y) {
    int m = X.size();
    int n = Y.size();

    // Create a 2D table to store lengths of LCS of substrings
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the dp array using a bottom-up dynamic programming approach
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // dp[m][n] contains the length of the LCS of X[0..m-1] and Y[0..n-1]
    return dp[m][n];
}

// Function to print the LCS itself
string printLCS(string X, string Y) {
    int m = X.size();
    int n = Y.size();
    
    // Create a 2D dp table for the length of the LCS
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill dp array using the same logic as the length calculation
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // To store the LCS
    string lcs = "";
    
    // Start from the bottom-right corner of the dp table
    int i = m, j = n;
    while (i > 0 && j > 0) {
        // If characters match, they are part of LCS
        if (X[i - 1] == Y[j - 1]) {
            lcs += X[i - 1];
            i--;
            j--;
        }
        // Move in the direction of the larger value
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // Since we added characters from the end, reverse the string
    return lcs;
}

int main() {
    string X, Y;

    cout << "Enter the first string: ";
    cin >> X;

    cout << "Enter the second string: ";
    cin >> Y;

    // Get the length of the LCS
    int length = LCS(X, Y);
    cout << "Length of Longest Common Subsequence: " << length << endl;

    // Get and print the LCS itself
    string lcs = printLCS(X, Y);
    reverse(lcs.begin(), lcs.end());
    cout << "Longest Common Subsequence: " << lcs << endl;

    return 0;
}
