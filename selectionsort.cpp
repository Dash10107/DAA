
#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr,int n){
    for (int i = 0;i<n-1;i++){
        int mini = i;
        for (int j = i+1;j<n;j++){
            if (arr[j]<arr[mini]){
                mini = j;
            }
        }
        swap(arr[mini],arr[i]);
    }
  cout << "After selection sort: " << "\n";
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
    selectionSort(arr,n);

    return 0;
}
