#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int mid, int r) {
    int n1 = mid-l+1;
    int n2 = r - mid;
    vector<int> l1(n1),r1(n2);
    for(int i=0;i<n1;i++) {
        l1[i] = arr[l+i];
    }
    for(int i=0;i<n2;i++) {
        r1[i] = arr[mid+i+1];
    }
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2) {
        if(l1[i] <= r1[j]) {
            arr[k] = l1[i];
            i++;
        }
        else {
            arr[k] = r1[j];
            j++;
        }
        k++;
    }
    while(i < n1) {
        arr[k] = l1[i];
        i++;
        k++;
    }
    while(j < n2) {
        arr[k] = r1[j];
        j++;
        k++;
    }
}

void way2MergeSort(int arr[], int l, int r){
    if(l < r) {
        int mid = l + (r-l)/2;

        way2MergeSort(arr, l, mid);
        way2MergeSort(arr, mid+1, r);

        merge(arr, l, mid, r);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++)
        cin >> arr[i];

    way2MergeSort(arr,0,n-1);

    for(int i=0;i<n;i++) 
        cout << arr[i] << ' ';
    cout << endl;

    return 0;
}