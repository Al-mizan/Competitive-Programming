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
#define Fill(v,x)       fill(v.begin(),v.end(),x)
#define cases(tc)       cout << "Case #" << tc << ": "
#define debug(args...)  cout << #args << " = " << args << endl;
#define getunique(v){sort(v.begin(), v.end());v.erase(unique(v.begin(), v.end()), v.end());}
template<typename T>istream &operator>>(istream &istream,vector<T>&v){for(auto &it:v)cin>>it;return istream;}
template<typename T>ostream &operator<<(ostream &ostream,const vector<T>&c){for(auto &it:c)cout<<it<<' ';return ostream;}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    cin >> v;
    int cnt = 0, a = -1,b = -1;
    for(int i=0;i<n;i++) {
        if(v[i] != k) {
            b = i;
            if(a == -1) a = i;
        }
        else cnt++;
    }
    if(cnt == n) {
        cout << 0 << endl;
        return;
    }
    bool f=1, g=1;
    int x = v[a]^k;
    for(int i = a; i <= b; i++) {
        if(v[i]%k != 0) f=0;
        if((v[i]^k) != x) g=0;
    }
    if(g || f) cout << 1 << endl;
    else cout << 2 << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
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