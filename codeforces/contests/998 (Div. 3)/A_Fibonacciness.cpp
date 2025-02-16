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
    ll a, b, d, e;
    cin >> a >> b >> d >> e;
    
    ll c = a+b;
    if(a+b==c && b+c==d && c+d==e){
        cout << 3 << endl;
        return;
    }
    c = d-b;
    ll c1 = a+b;
    if((b+c==d && c+d==e) ||(a+b==c1 && b+c1==d) || (a+b==c1 && c1+d==e)) {
        cout << 2 << endl;
        return;
    }
    
    if(a+b==c || b+c==d || c+d==e) {
        cout << 1 << endl;
        return;
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
        // cases(tc);
        solve();
    }
    return 0;
}
