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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    
    bool f = 0; int ind = -1, cnt = 0, maxi = 0, i;
    for(i=0; i<n; i++) if(s[i] == '1') break;
    for(; i<n; i++) if(s[i] == '0') break;
    for(; i<n; i++) {
        if(s[i] == '0') ind = i;
        else break;
    }

   
    int ind2 = -1;
    for(int i=0; i<n; i++) {
        if(s[i] == '1') {
            ind2 = i;
            break;
        }
    }
    if(ind!=-1) {
        ind++;
        reverse(s.begin()+ind2, s.begin()+ind);
    }

    ll ans = s[0]=='1'? 2: 1;
    for(int i=1; i<n; i++) {
        ans += (s[i]!=s[i-1]? 2: 1);
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}