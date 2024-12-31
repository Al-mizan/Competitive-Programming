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

const int n = 1e6;
bool pr[n];
vector<int> prime;
void sieve()
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
   for(int i=2;i<=n;i++) if(pr[i]==true) prime.push_back(i);
}

void solve() {
    ll n;
    cin >> n;
    if(n < 7) no;
    else yes;
    
}

int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        // cases(tc);
        solve();
    }
    return 0;
}
