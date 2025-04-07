#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> mat(n, vector<ll>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    ll maxSum = LLONG_MIN;

    for (int top = 0; top < n; top++) {
        vector<ll> temp(m, 0);

        for (int bot = top; bot < n; bot++) {
            for (int col = 0; col < m; col++) {
                temp[col] += mat[bot][col];
            }
            ll currSum = 0, bestSum = LLONG_MIN;
            for (int col = 0; col < m; col++) {
                currSum += temp[col];
                bestSum = max(bestSum, currSum);
                if (currSum < 0) currSum = 0;
            }
            maxSum = max(maxSum, bestSum);
        }
    }

    cout << maxSum << endl;
}

int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
