#include <bits/stdc++.h>
using namespace std;

vector<int> prefixSum1D(vector<int>& arr) {
    int n = arr.size();
    vector<int> psum(n);
    psum[0] = arr[0];
    for (int i = 1; i < n; i++) 
        psum[i] = psum[i - 1] + arr[i];
    return psum;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    
    vector<int> psum1D = prefixSum1D(arr);
    cout << endl;
    for (int x : psum1D) 
        cout << x << " ";
    cout << endl;

    return 0;
}