#include<bits/stdc++.h>
using namespace std;

vector<int> LPS(const string& pattern) {
    int m = pattern.size();
    vector<int> lps(m);
    int j = 0, i = 1;
    while(i < m) {
        if(pattern[i]==pattern[j]) {
            j++;
            lps[i] = j;
            i++;
        }
        else {
            if(j != 0) j = lps[j-1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int KMP_search(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> lps = LPS(pattern);
    int i = 0, j = 0, cnt = 0;
    while(i < n) {
        if(pattern[j] == text[i]) {
            i++;
            j++;
        }
        if(j==m) {
            cnt++;
            j = lps[j-1];
        }
        else if(i<n && pattern[j] != text[i]) {
            if(j != 0) j = lps[j-1];
            else i++;
        }
    }
    return cnt;
}

int main() {
    string text, pattern;
    cin >> text >> pattern;

    cout << KMP_search(text, pattern) << endl;
    return 0;
}
