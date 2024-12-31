#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the length of the Longest Increasing Subsequence
int LIS(vector<int>& arr) {
    vector<int> lis;  // This will store the current LIS

    // Traverse the array
    for (int i = 0; i < arr.size(); i++) {
        // Use binary search to find the index of the smallest element in lis
        // that is greater than or equal to arr[i]
        auto it = lower_bound(lis.begin(), lis.end(), arr[i]);

        // If arr[i] is larger than any element in lis, append it to lis
        if (it == lis.end()) {
            lis.push_back(arr[i]);
        }
        // Otherwise, replace the element at the found index with arr[i]
        else {
            *it = arr[i];
        }
    }

    // The size of lis is the length of the Longest Increasing Subsequence
    return lis.size();
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the LIS function and output the result
    int length = LIS(arr);
    cout << "Length of the Longest Increasing Subsequence is: " << length << endl;

    return 0;
}
