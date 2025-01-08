#include <iostream>
#include <vector>
using namespace std;

// Update BIT: Add `val` to index `idx`
void update(vector<long long> &bit, int idx, long long val) {
    int n = bit.size();
    while (idx < n) {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

// Query BIT: Get the prefix sum up to index `idx`
long long query(const vector<long long> &bit, int idx) {
    long long sum = 0;
    while (idx > 0) {
        sum += bit[idx];
        idx -= idx & -idx;
    }
    return sum;
}

// Perform range update on BIT1 and BIT2
void rangeUpdate(vector<long long> &BIT1, vector<long long> &BIT2, int l, int r, long long val) {
    update(BIT1, l, val);
    update(BIT1, r + 1, -val);
    update(BIT2, l, val * (l - 1));
    update(BIT2, r + 1, -val * r);
}

// Get prefix sum at index `idx`
long long prefixSum(const vector<long long> &BIT1, const vector<long long> &BIT2, int idx) {
    return query(BIT1, idx) * idx - query(BIT2, idx);
}

// Get sum of range [l, r]
long long rangeSum(const vector<long long> &BIT1, const vector<long long> &BIT2, int l, int r) {
    return prefixSum(BIT1, BIT2, r) - prefixSum(BIT1, BIT2, l - 1);
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<long long> BIT1(n + 1, 0), BIT2(n + 1, 0);

    cout << "Enter the initial array values (1-based indexing): ";
    vector<long long> arr(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        rangeUpdate(BIT1, BIT2, i, i, arr[i]); // Initialize BITs with array values
    }

    int q;
    cout << "Enter the number of queries: ";
    cin >> q;

    cout << "Queries can be of two types:\n";
    cout << "1 l r val - Add `val` to the range [l, r]\n";
    cout << "2 l r     - Get the sum of range [l, r]\n";

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            // Range update
            int l, r;
            long long val;
            cin >> l >> r >> val;
            rangeUpdate(BIT1, BIT2, l, r, val);
        } else if (type == 2) {
            // Range query
            int l, r;
            cin >> l >> r;
            cout << rangeSum(BIT1, BIT2, l, r) << endl;
        } else {
            cout << "Invalid query type!" << endl;
        }
    }

    return 0;
}
