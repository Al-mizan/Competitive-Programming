#include <bits/stdc++.h>
using namespace std;

int LCS(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

string printLCS(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();    
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string lcs = "";
    int i = m, j = n;

    while (i > 0 && j > 0) {
        if (text1[i - 1] == text2[j - 1]) {
            lcs += text1[i - 1];
            i--; j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) i--; // Move in the direction of the larger value
        else j--;
    }
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main() {
    string text1, text2;
    cin >> text1 >> text2;

    int length = LCS(text1, text2);
    cout << "Length of Longest Common Subsequence: " << length << endl;

    string lcs = printLCS(text1, text2);
    cout << "Longest Common Subsequence: " << lcs << endl;

    return 0;
}
