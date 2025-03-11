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

void solve() {
    string s;
    cin >> s;
    
    for(int i=1; i<s.size(); i++) {
        if(s[i] == '0') continue;
        int x = s[i] - '0', j;
        char ch = '$';
        for(j=8; j>=1; j--) {
            if(i-j >= 0) {
                int y = s[i-j] - '0';
                if(y < x-j) {
                    ch = x - j + '0';
                    break;
                }
            }
        }
        if(ch == '$') continue;
        for(int k=i; k>i-j; k--) {
            swap(s[k], s[k-1]);
        }
        s[i-j] = ch;
    }

    cout << s << endl;
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}