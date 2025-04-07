#include <bits/stdc++.h>
using namespace std;

int edit_distance(string word1, string word2, int insert_cost, int delete_cost, int replace_cost) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Base cases:
    // Converting word1[0..i-1] to empty string (delete all characters)
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i * delete_cost;
    }
    // Converting empty string to word2[0..j-1] (insert all characters)
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j * insert_cost;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1]; // Characters match, no cost
            }
            else {
                dp[i][j] = min({
                    dp[i-1][j-1] + replace_cost,
                    dp[i-1][j] + delete_cost,
                    dp[i][j-1] + insert_cost });
            }
        }
    }

    return dp[m][n];
}

int main() {
    string word1, word2;
    cin >> word1 >> word2;

    int insert_cost = 1; // by default value is 1
    int delete_cost = 1;
    int replace_cost = 1;
    cin >> insert_cost >> delete_cost >> replace_cost;

    // convert word1 to word2
    int result = edit_distance(word1, word2, insert_cost, delete_cost, replace_cost);  
    cout << "Minimum edit distance: " << result << endl;

    return 0;
}