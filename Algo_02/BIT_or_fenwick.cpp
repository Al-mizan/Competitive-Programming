#include <iostream>
#include <vector>
using namespace std;

// Update function for 0-based BIT.
// 'bit' is the Binary Indexed Tree vector,
// 'n' is the size of the original array,
// 'i' is the index to update (0-indexed),
// and 'val' is the value to add.
void update(vector<int>& bit, int n, int i, int val) {
    // In 0-based BIT, we update while i is within the array.
    for (; i < n; i = i | (i + 1))
        bit[i] += val;
}

// Query function for 0-based BIT.
// Returns the prefix sum from index 0 to i (inclusive).
int query(const vector<int>& bit, int i) {
    int sum = 0;
    // Move backward through the tree structure.
    for (; i >= 0; i = (i & (i + 1)) - 1)
        sum += bit[i];
    return sum;
}

int main() {
    // Let's say the size of our original array is n.
    int n = 10;
    
    // Initialize the BIT vector with n elements (0-indexed).
    vector<int> bit(n, 0);
    
    // Suppose we have an array: [1, 2, 3, ..., 10].
    // Build the BIT by updating each index with the corresponding value.
    // Remember that our indices are 0-based.
    for (int i = 0; i < n; i++) {
        update(bit, n, i, i + 1);  // i+1 gives us the value at position i.
    }
    
    // Query the prefix sum from index 0 to 4 (equivalent to sum of first 5 elements).
    cout << "Prefix sum from index 0 to 4: " << query(bit, 4) << endl;
    
    // To query a range sum from index L to R, use:
    // rangeSum(L, R) = query(R) - query(L-1) [if L > 0], otherwise query(R) if L is 0.
    int L = 2, R = 6;  // This will give the sum from the 3rd to the 7th element.
    int rangeSum = query(bit, R) - (L > 0 ? query(bit, L - 1) : 0);
    cout << "Range sum from index 2 to 6: " << rangeSum << endl;
    
    return 0;
}
