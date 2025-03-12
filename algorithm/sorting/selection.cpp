#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0;i<n;i++) {
        int ind = 0;
        for(int j=0;j<n-i-1;j++) {
            if(arr[j] < arr[j+1]) {
                ind = j+1;
            }
        }
        swap(arr[ind], arr[n-i-1]);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++)
        cin >> arr[i];

    selectionSort(arr,n);

    cout << endl;
    for(int i=0;i<n;i++) 
        cout << arr[i] << ' ';
    cout << endl;

    return 0;
}