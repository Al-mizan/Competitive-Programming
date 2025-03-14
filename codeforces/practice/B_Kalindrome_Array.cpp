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
    
    ll cnt1 = 0, l = 0, r = n-1, mm = INT_MAX;
    while(l < r) {
        if(v[r] == mm) {
            r--; continue;
        }
        if(v[l] == mm) {
            l++; continue;
        }
        if(v[l] != v[r]) {
            cnt1++;
            mm = v[r];
        }
        else l++, r--;

        if(cnt1 > 1) break;
    }
    ll cnt2 = 0; l = 0, r = n-1, mm = INT_MAX;
    while(l < r) {
        if(v[r] == mm) {
            r--; continue;
        }
        if(v[l] == mm) {
            l++; continue;
        }
        if(v[l] != v[r]) {
            cnt2++;
            mm = v[l];
        }
        else l++, r--;

        if(cnt2 > 1) break;
    }
    
    if(cnt1 <= 1 or cnt2 <=1) yes;
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
