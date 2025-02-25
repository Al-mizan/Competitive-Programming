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
    string s;
    cin >> s;
    
    ll sum = 0;
    for (int i = 0; i < s.size(); i++)
        sum += s[i] - '0';
    
    int two = 0, three = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '2') two++;
        else if(s[i] == '3') three++;
    }
    int tt[] = {0, 2, 4, 6, 8, 1, 3, 5, 7};
    int th[] = {0, 6, 3};
    
    for(int i = 0; i < min(9,two+1); i++) {
        for(int j = 0; j < min(3,three+1); j++) {
            if((sum + tt[i] + th[j]) % 9 == 0) {
                yes; return;
            }
        }
    }
    no;
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}