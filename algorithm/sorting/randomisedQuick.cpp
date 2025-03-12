#include<bits/stdc++.h>
using namespace std;

// random pivot

int partition(int arr[], int l, int r) {
    srand(time(NULL));
    int random = l + rand()%(r-l);
    swap(arr[r], arr[random]);
    int pivot = arr[r];
    int k = l;
    for(int i=l; i<r; i++) {
        if(arr[i] < pivot) {
            swap(arr[k], arr[i]);
            k++;
        }
    }
    swap(arr[k], arr[r]);
    return k;
}

void quickSort(int arr[], int l, int r){
    if(l < r) {
        int pi = partition(arr, l, r);

        quickSort(arr, l, pi-1);
        quickSort(arr, pi+1, r);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++)
        cin >> arr[i];

    quickSort(arr,0,n-1);

    for(int i=0;i<n;i++) 
        cout << arr[i] << ' ';
    cout << endl;

    return 0;
}