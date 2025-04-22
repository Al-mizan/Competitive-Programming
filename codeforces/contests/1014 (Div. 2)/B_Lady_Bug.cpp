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
    string a,b;
    cin >> a >> b;
    
    ll odd = 0, even = 0, cnt = 0;
    bool f = 0;
    for(int i=0; i<n-1; i++) {
        if(a[i] == '1' && b[i+1] == '0') {
            swap(a[i], b[i+1]);
        }
        else if(a[i] == '1' && b[i+1] == '1') {
            (i%2==0) ? odd++ : even++;
        }
    }
    if(a[n-1]=='1') ((n-1)%2==0) ? odd++ : even++;
    
    for(int i=0; i<n; i++) {
        if(b[i] == '0') {
            if(i%2) odd--;
            else even--;
        }
    }
    // debug(odd);
    // debug(even);
    if(odd <= 0 && even <= 0) yes;
    else no;
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}