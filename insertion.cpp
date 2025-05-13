
#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr,int n){
    
    for (int i = 0;i<n-1;i++){
        int j = i;
        while (j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
        cout << "After Using insertion sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0;i<n;i++){
        cin>>arr[i];
    }
    insertionSort(arr,n);

    return 0;
}
