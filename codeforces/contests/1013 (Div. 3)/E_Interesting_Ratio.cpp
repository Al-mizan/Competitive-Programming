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

const int N = 1.02e7;
bool pr[N]; 
vector<int> prime;
void sieve(ll n) {
    memset(pr,true ,sizeof(pr));
    for(ll p=2;p*p<=n;p++) {
        if(pr[p]==1) {
            for(int i=p*p;i<=n;i+=p) {
                pr[i]=false;
            }
        }
    }
    for(int i=2;i<=n;i++) 
        if(pr[i]==true) prime.push_back(i);
}

void solve() {
    ll n;
    cin >> n;
    ll ans = 0;
    for(auto p: prime) {
        if (p > n) break;
        ans += (n/p);
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    sieve(1e7);    
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}