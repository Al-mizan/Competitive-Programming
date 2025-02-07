#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Function to compute the Z-array for a given string
vector<int> computeZ(const string &s) {
    int n = s.size();
    vector<int> Z(n, 0);
    int L = 0, R = 0;
    
    for (int i = 1; i < n; i++) {
        if (i <= R) {
            Z[i] = min(R - i + 1, Z[i - L]);
        }
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) {
            Z[i]++;
        }
        if (i + Z[i] - 1 > R) {
            L = i;
            R = i + Z[i] - 1;
        }
    }
    return Z;
}

int main() {
    // Input pattern and text
    string pattern, text;
    cout << "Enter pattern: ";
    cin >> pattern;
    cout << "Enter text: ";
    cin >> text;

    // Create the concatenated string "pattern + '$' + text"
    // The delimiter '$' must be a character that doesn't appear in the pattern or text.
    string concat = pattern + "$" + text;
    
    // Compute Z-array for the concatenated string
    vector<int> Z = computeZ(concat);
    
    // Pattern length to compare with Z-values
    int pLen = pattern.size();
    
    // Store the starting indices (0-indexed) of pattern occurrences in the text
    vector<int> occurrences;
    
    // The pattern occurrences start after the delimiter, at index positions:
    // i - pLen - 1 in the text when Z[i] == pLen
    for (int i = 0; i < Z.size(); i++) {
        if (Z[i] == pLen) {
            // Calculate the index in the text (subtract pattern length and delimiter)
            occurrences.push_back(i - pLen - 1);
        }
    }
    
    // Output the results
    if (occurrences.empty()) {
        cout << "No occurrences found." << endl;
    } else {
        cout << "Pattern found at index positions: ";
        for (int idx : occurrences)
            cout << idx << " ";
        cout << endl;
    }
    
    return 0;
}
