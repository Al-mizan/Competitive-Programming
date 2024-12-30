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

const int N = 1e5; // limit for array size
int n;             // array size
int t[2 * N];      // segment tree array

void build() { // build the tree
	for (int i = n - 1; i > 0; --i)
		t[i] = t[i << 1] + t[i << 1 | 1];
}

void modify(int l, int r, int value) {
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) t[l++] += value;
		if (r&1) t[--r] += value;
	}
}

int query(int l, int r) { // sum on interval [l, r)
	int res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1)
			res += t[l++];
		if (r & 1)
			res += t[--r];
	}
	return res;
}
void solve() {
	cin >> n;
	vector<int> A(n);
	cin >> A;
	for (int i = 0; i < n; i++)
		t[n+i] = A[i];
	build();
    ll q;
    cin >> q;
    while(q--) {
        ll type,l, r, val;
        cin >> type >> l >> r;
		if(type)
			cout << query(l-1, r) << endl;
		else {
			cin >> val;
			modify(l,r,val);
		}
    }
}
int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}