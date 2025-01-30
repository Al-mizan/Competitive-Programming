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

ull nCr(int n, int r){
    if(r>n || r<0) return 0;
    if(r==n || r==0) return 1;
    ll sum = 1ULL;
    for(int i = 1; i <= r; i++){
        sum = (sum * (n - r + i) / i);
    }
    return sum;
}

void solve() {
    string s, p;
    cin >> s >> p;
    map<char, int> mp;
    for(auto a: p) mp[a]++;

    if(mp.size()==1 && mp['a'] == 1) {
        cout << 1 << endl;
    }
    else if(mp['a'] && mp.size()>=1) {
        cout << "-1\n";
    }
    else {
        ll n = s.size();
        ull sum = 0;
        for(int i=0; i<=n; i++) {
            sum += nCr(n,i);
        }
        
        cout << sum << endl;
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
