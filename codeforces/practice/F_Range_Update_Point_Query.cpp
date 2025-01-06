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

const int N = 2*1e5 + 5;
ll arr[N], lazy[N]; // Fenwick Tree arrays
vector<ll> v;

// void build(ll val, ll n, ll idx) {
//     while (idx <= n) {
//         arr[idx] += val;
//         idx += (idx & -idx);
//     }
// }

// void update(vector<ll>& v, ll n, ll l) {
//     while (l <= n) {
//         ll sum = 0;
//         ll x = v[l];
//         while(x) {
//             sum += x % 10;
//             x /= 10;
//         }
//         arr[l] += sum - v[l];
//         l += (l & -l);
//     }
// }
void update(ll idx, ll val, ll n) {
    while (idx <= n) {
        arr[idx] += val;
        idx += (idx & -idx);
    }
}

ll query(ll ind) {
    ll sum = 0;
    while(ind > 0) {
        sum += arr[ind];
        ind -= (ind & -ind);
    }
    return sum;
}

void range_update(ll l, ll r, ll n) {
    while (l <= r) {
        if (lazy[l] == 0) { // Apply digit sum update only once
            ll digitSum = 0, temp = v[l];
            while (temp > 0) {
                digitSum += temp % 10;
                temp /= 10;
            }
            update(l, digitSum - v[l], n); // Update Fenwick Tree
            v[l] = digitSum;                    // Update original array
            lazy[l] = 1;                        // Mark as updated
        }
        l += (l & -l); // Jump to next index based on Fenwick Tree logic
    }
}

void solve() {
    ll n, q;
    cin >> n >> q;
    v.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        update(v[i], n, i);
    }
    // // for(int i = 0; i < n; i++) {
    // //     cout << arr[i+1] << " ";
    // // }
    // newline;
    while(q--) {
        int x;
        cin >> x;
        if(x == 1) {
            ll l, r;
            cin >> l >> r;
            range_update(l, r, n);
        }
        else {
            ll ind;
            cin >> ind;
            cout << query(ind) - query(ind-1) << endl;
        }
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
        memset(arr, 0, sizeof(arr));
        memset(lazy, 0, sizeof(lazy));
        solve();
    }
    return 0;
}
