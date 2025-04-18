#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl            '\n'
#define inf             1e18
#define ff              first
#define ss              second
#define pb              push_back
#define mod             1000000007 
#define newline         cout << '\n'
#define no              cout << "NO\n"
#define yes             cout << "YES\n"
#define all(A)          A.begin(), A.end()
#define rall(A)         A.rbegin(), A.rend()
#define mem(A,n)        memset(A, n, sizeof(A))
#define debug(args...)  cout << #args << " = " << args << endl;
template<typename T>istream &operator>>(istream &istream,vector<T>&v){for(auto &it:v)cin>>it;return istream;}
template<typename T>ostream &operator<<(ostream &ostream,const vector<T>&c){for(auto &it:c)cout<<it<<' ';return ostream;}

int func(string s, char ch, int cnt, bool ck) {
    int ans = 0;
    while(s.size()>cnt) {
        string temp = "";
        bool check = ck;
        for(auto c: s) {
            // debug(check);
            if (c == ch || check) temp += c, check=0;
            else check = !check;
        }
        ans++;
        s = temp;
        // debug(s);
        if(ans > 50) break;
    }
    return ans;
}

void solve() {
    string s;
    cin >> s;

    char ch; int cnt = 0;
    map<char,int> mp;
    for(auto c: s) mp[c]++;
    for(auto c: mp) {
        if (c.ss > cnt) {
            cnt = c.ss; ch = c.ff;
        }
    }
    if(cnt == 1) cout << (int)log2(s.size()) << endl;
    else {
        int mini = INT_MAX;
        for(auto c: mp) {
            if (c.ss == cnt) {
                mini = min(mini, min(func(s,c.ff,cnt,1),func(s,c.ff,cnt,0)));
            }
        }
        cout << mini << endl;
    }
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}