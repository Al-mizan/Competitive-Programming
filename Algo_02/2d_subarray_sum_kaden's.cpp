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

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> matrix(n, vector<ll>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    ll maxSum = LLONG_MIN;

    // Fix the top row
    for (int top = 0; top < n; top++) {
        // Create a temporary array to store column sums
        vector<ll> temp(m, 0);

        // Expand the bottom row
        for (int bottom = top; bottom < n; bottom++) {
            // Add the current row's values to the temp array
            for (int col = 0; col < m; col++) {
                temp[col] += matrix[bottom][col];
            }

            // Apply Kadane's algorithm on the temp array
            ll currSum = 0, bestSum = LLONG_MIN;
            for (int col = 0; col < m; col++) {
                currSum += temp[col];
                bestSum = max(bestSum, currSum);
                if (currSum < 0) currSum = 0;
            }

            // Update the global maximum
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
