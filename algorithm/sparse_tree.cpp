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

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    cin >> v;

    ll h = log2(n) + 1;
    ll arr[h][n];
    for (int i = 0; i < n; i++)
        arr[0][i] = v[i];

    for(int i = 1; i < h; i++) {
        for(int j = 0; j < n; j++) {
            if((j+(1 << i)-1) < n) {
                arr[i][j] = max(arr[i-1][j], arr[i-1][j + (1 << (i-1))]);
            }
        }
    }

    ll q;
    cin >> q;
    while(q--) {
        ll l, r;
        cin >> l >> r;
        l--; r--;
        ll pos = log2(r-l+1);

        cout << max(arr[pos][l], arr[pos][r-(1<<pos)+1]) << endl;
    }
}

int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
