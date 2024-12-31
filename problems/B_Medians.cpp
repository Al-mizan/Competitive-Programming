#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl            '\n'
#define ff              first
#define ss              second
#define pi              acos(-1)
#define mod             1000000007 
#define newline         cout << '\n'
#define no              cout << "NO\n"
#define yes             cout << "YES\n"
#define all(A)          A.begin(), A.end()
#define rall(x)         x.rbegin(), x.rend()
#define mem(a,n)        memset(a, n, sizeof(a))
#define setPre(n)       fixed << setprecision(n)
#define cases(tc)       cout << "Case #" << tc << ": "
#define debug(args...)  cout << #args << " = " << args << endl;
template<typename T>istream &operator>>(istream &istream,vector<T>&v){for(auto &it:v)cin>>it;return istream;}
template<typename T>ostream &operator<<(ostream &ostream,const vector<T>&c){for(auto &it:c)cout<<it<<' ';return ostream;}

void print1(ll k) {
    for(int i = 1; i < k; i++) {
            cout << i << ' ';
    }
}
void print2(ll k) {
    for(int i = 1; i < k-1; i++) {
        cout << i+k+1 << ' ';
    }
}

void solve() {
    ll n, k;
    cin >> n >> k;
    if((k == n || k == 1) && n != 1) {
        cout << -1 << endl;
        return;
    }
    if (k == 1) {
        cout << 1 << endl;
        cout << 1 << endl;
    }
    else if(k == 2) {
        cout << 3 << endl;
        cout << 1 << ' ' << 2 << ' ' << 3 << endl;
    }
    else if(k == n-1) {
        cout << 3 << endl;
        cout << 1 << ' ' << n-1 << ' ' << n << endl;
    }
    else {
        if(n/2 +1 < k) {
            cout << 2*(n -k -1) + 1 << endl;
            print1(n-k);
            cout << k-1 << ' ';
            for(int i =k+2; i<=n; i++) 
                cout << i << ' ';
        }
        else {
            cout << 2*(k - 2) + 1 << endl;
            print1(k);
            print2(k);
        }
        newline;
    }
}

int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
