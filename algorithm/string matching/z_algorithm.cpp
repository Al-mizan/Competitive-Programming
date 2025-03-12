#include<bits/stdc++.h>
using namespace std;

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int z_algo(const string& text, const string& pattern) {
    string combined = pattern + "$" + text;
    vector<int> pi = z_function(combined);
    int cnt = 0;
    int l = pattern.size();

    for (int i = l + 1; i < combined.size(); i++) {
        if (pi[i] == l) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    string text, pattern;
    cin >> text >> pattern;

    cout << z_algo(text, pattern) << endl;
    return 0;
}

