#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(int i=0;i<n;i++) 
        cin >> v[i];
    
    ll m = sqrt((ld)n);
    ll pre[(n+m-1)/m]{};
    ll maxi = INT_MIN;
    int j = 0;
    for(int i = 0; i <n; i++) {
        maxi = max(maxi, v[i]);
        if(i && ((i+1)%m == 0)) {
            pre[j++] = maxi;
            maxi = INT_MIN;
        }
    }
    if(maxi != INT_MIN) pre[j] = maxi;
    
    ll q;
    cin >> q;
    while(q--) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        ll ans = INT_MIN;

        for(int i = a; i <= min(b, (a/m + 1)*m -1); i++)
            ans = max(ans,v[i]);

        for(int i = a/m; i < b/m; i++)
            ans = max(ans,pre[i]);

        for(int i = (b/m)*m; i <= b; i++)
            ans = max(ans,v[i]);

        cout << ans << endl;
    }
}

int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    solve();

    return 0;
}
