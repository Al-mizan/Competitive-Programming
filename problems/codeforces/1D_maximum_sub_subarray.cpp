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
    
    priority_queue< pair<ll,pair<ll,ll>>> pq;
    ll sum = 0, max_sum = 0;
    ll l = 0, r = -1;
    for(int i=0;i<n;i++) {
        sum += v[i];
        if(sum > max_sum) {
            max_sum = sum;
            r = i;
            pq.push({r-l+1,{l,r}});
        }
        if(sum < 0) {
            sum = 0;
            l = i+1;
        }
    }
    cout << max_sum << endl;
    if(max_sum == 0) {
        cout << *max_element(all(v)) << endl;
        return;
    }
    ll l_final = pq.top().ss.ff;
    ll r_final = pq.top().ss.ss;
    // cout << l_final << ' ' << r_final << endl;

    for(int i=l_final;i<=r_final;i++) {
        cout << v[i] << ' ';
    }
    newline;
}

int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
