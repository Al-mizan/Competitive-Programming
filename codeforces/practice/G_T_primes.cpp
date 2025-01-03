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

const int N = 1e6+100;
bool pr[N];
void sieve(ll n)
{
    memset(pr,true ,sizeof(pr));
    for(ll p=2;p*p<=n;p++)
    {
        if(pr[p]==1)
        {
            for(int i=p*p;i<=n;i+=p)
            {
                pr[i]=false;
            }
        }
    }
}
void solve() {
    ll n;
    cin >> n;
    ll x;
    while(n--) {
        cin >> x;
        ll rt = sqrt(x);
        if(rt*rt == x && pr[rt] && x !=1) yes;
        else no;
    }    
}

int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    sieve(1e6+99);
    int t = 1;
    while (t--)
    {
        // cases(tc);
        solve();
    }
    return 0;
}
