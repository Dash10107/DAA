#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr,int l,int r){
    int pivot = arr[l];
    int i=l;
    int j =r;
    while (i<j){
        while (arr[i]<=pivot && i<=r-1){
            i++;
        }
        while (arr[j]>=pivot && j>=l+1){
            j--;
        }
        if (i<j) swap(arr[i],arr[j]);
        
    }
    swap(arr[l],arr[j]);
    return j;
}

void quickSort(vector<int> &arr,int left,int right){
    if (left<right){
        int pInd = partition(arr,left,right);
        quickSort(arr,left,pInd-1);
        quickSort(arr,pInd+1,right);
    }
}
void merge(vector <int> &arr,int mid,int left,int right){
    int i = left;
    int j = mid+1;
    vector<int> temp;
    while (i<=mid && j<=right){
        if (arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while (j<=right){
        temp.push_back(arr[j]);
        j++;
    }
    for(int k = left;k<=right;k++){
        arr[k]=temp[k-left];
    }
}

void mergeSort(vector<int> &arr,int left,int right){
    if (left>=right) return;
    int mid = (left+right)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,mid,left,right);
    
}


int main()
{
    int n;
    cout<<"Enter no of elements : ";
    cin>>n;

    vector<int> arr(n);
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl;
    mergeSort(arr,0,n-1);
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
