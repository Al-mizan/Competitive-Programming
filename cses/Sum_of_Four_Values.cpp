#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl            '\n'
#define inf             1e18
#define ff              first
#define ss              second
#define pb              push_back
#define mod             1000000007 
#define newline         cout << '\n'
#define no              cout << "NO\n"
#define yes             cout << "YES\n"
#define all(A)          A.begin(), A.end()
#define rall(A)         A.rbegin(), A.rend()
#define mem(A,n)        memset(A, n, sizeof(A))
#define debug(args...)  cout << #args << " = " << args << endl;
template<typename T>istream &operator>>(istream &istream,vector<T>&v){for(auto &it:v)cin>>it;return istream;}
template<typename T>ostream &operator<<(ostream &ostream,const vector<T>&c){for(auto &it:c)cout<<it<<' ';return ostream;}

void solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    set<pair<ll,pair<int,int>>> st;
    cin >> v;
    
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            st.insert({v[i]+v[j],{i,j}});
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            ll sum = v[i]+v[j];
            if(sum > x) continue;

            auto it = st.lower_bound({x-sum, {INT_MAX,INT_MAX}});
            if(it == st.begin()) continue;
            it--;
            if(it == st.begin()) continue;
            auto it2 = st.lower_bound({x-sum, {INT_MIN,INT_MIN}});
            
            if(it2 == st.end() && it == st.end() && it->ff != x-sum && it2->ff != x-sum) continue;
            
            for (auto k = it2; k != next(it); k++) {
                if(k->ff == x-sum && k->ss.ff != i && k->ss.ss != i && k->ss.ff != j && k->ss.ss != j) {
                    cout << i+1 << " " << j+1 << " " << k->ss.ff+1 << " " << k->ss.ss+1 << endl;
                    return;
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}