#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool subset(vector<int> &arr,int n,int k){
    if (k==0){
        return true;
    }
    if (n==0){
        return arr[0]==k;
    }
        bool notTake=subset(arr,n-1,k);
        bool take = false;
        if (arr[n]<=k)take = subset(arr,n-1,k-arr[n]);
        return take || notTake;    
    
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<<subset(arr,n-1,k);
    return 0;
}
