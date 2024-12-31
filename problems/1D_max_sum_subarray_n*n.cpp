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
    
    ll sum = 0, max_sum = 0;
    ll l = -1, r = -1;
    for(int i=0;i<n;i++) {
        int j;
        for(j=i;j<n;j++) {
            sum += v[j];
            if(sum > max_sum) {
                max_sum = sum;
                l = i, r = j;    
            }
            if(sum < 0) break;
        }
        sum = 0;
    }
    if(max_sum <= 0) {
        cout << *max_element(all(v)) << endl;
        cout << *max_element(all(v)) << endl;
        return;
    }
    cout << max_sum << endl;

    for(int i=l;i<=r;i++) {
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
