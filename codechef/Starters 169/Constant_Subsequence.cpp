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

bool valid(ll val, vector<ll>& pos, vector<ll>& neg) {
    ll sum = 0, l = 0;
    for(auto &it:pos) {
        if(it > val) return false;
        sum += it;
        while(val < sum && l < neg.size()) {
            sum += neg[l++];
            sum = max(sum, it);
        }
    }

    return sum <= val;
}


void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n), pos, neg;
    cin >> v;

    for(int i=0; i<n; i++) {
        if(v[i] >= 0) pos.push_back(v[i]);
        else neg.push_back(v[i]);
    }

    ll l = 0, r = accumulate(all(pos), 0LL);
    while(l < r) {
        ll mid = ((r-l)>>1) + l;
        
        if(valid(mid, pos, neg)) r = mid; // debug(r);}
        else l = mid + 1; //debug(l);
    }
    ll maxi = *max_element(all(v));

    cout << max(l,maxi) << endl;
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
