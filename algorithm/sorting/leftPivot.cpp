#include <bits/stdc++.h>
using namespace std;

// Left pivot partition function
int partition(int arr[], int l, int r) {
    int pivot = arr[l];  // Leftmost element as pivot
    int i = l + 1;  // Index to place smaller elements
    for (int j = l + 1; j <= r; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);  // Move smaller element to the left
            i++;
        }
    }
    swap(arr[l], arr[i - 1]);  // Place the pivot in its correct position
    return i - 1;  // Return the pivot's position
}

// Quicksort function
void quickSort(int arr[], int l, int r) {
    if (l < r) {
        int pi = partition(arr, l, r);  // Partition the array
        quickSort(arr, l, pi - 1);  // Sort the left subarray
        quickSort(arr, pi + 1, r);  // Sort the right subarray
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;

    return 0;
}
