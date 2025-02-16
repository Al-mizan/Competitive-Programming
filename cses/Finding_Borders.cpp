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

void z_algo(const string& pattern) {
    string combined = pattern;
    vector<int> pi = z_function(combined);
    int cnt = 0;
    int l = pattern.size();

    vector<int> res;
    for(int i = 0; i < l; i++) {
        if(pi[i] == l-i) res.push_back(pi[i]);
    }
    sort(res.begin(), res.end());
    for(auto x : res) 
        cout << x << " ";
    cout << endl;
}

int main() {
    string pattern;
    cin >> pattern;

    z_algo(pattern);
    return 0;
}

