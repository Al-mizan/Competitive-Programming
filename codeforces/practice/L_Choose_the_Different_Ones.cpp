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
#define setPre(n)       fixed << setprecision(n)
#define cases(tc)       cout << "Case #" << tc << ": "
#define debug(args...)  cout << #args << " = " << args << endl;
template<typename T>istream &operator>>(istream &istream,vector<T>&v){for(auto &it:v)cin>>it;return istream;}
template<typename T>ostream &operator<<(ostream &ostream,const vector<T>&c){for(auto &it:c)cout<<it<<' ';return ostream;}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    map<ll, ll> mp1, mp2;

    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        if(x <= k) mp1[x]++;
    }
    for(int i=0;i<m;i++) {
        int x;
        cin >> x;
        if(x <= k) mp2[x]++;
    }

    int cnt = 0, cnt1 = 0, cnt2 =0;
    for(int i=1; i<=k; i++) {
        if(mp1[i] && mp2[i]) cnt++;
        else {
            if(mp1[i]) cnt1++;
            if(mp2[i]) cnt2++;
        }
    }
    cnt1 = cnt1 > k/2 ? k/2 : cnt1;
    cnt2 = cnt2 > k/2 ? k/2 : cnt2;
    if(k-cnt1-cnt2 <= cnt) yes;
    else no;
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
