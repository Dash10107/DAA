#include<bits/stdc++.h>
#include <iostream>
using namespace std;

double fractionknap(vector<pair<double,pair<int,int>>> &knap,int W,int n){
    double ans = 0.0;
sort(knap.begin(), knap.end(), [](auto &a, auto &b) {
    return a.first > b.first;
});

    for(int i = 0;i<n;i++){
        int w = knap[i].second.first;
        int prof = knap[i].second.second;
        if (w<=W){
            W-=w;
            ans+=prof;
        }
        else{
            ans+= knap[i].first*W;
            break;
        }
    }
    return ans;

}

int main()
{
    int n;
    cin>>n;
    
    vector<pair<double,pair<int,int>>> knaps(n);
    for (int i= 0;i<n;i++){
        int w,prof;
        cin>>w>>prof;
        double cost = (double)prof/w;
        knaps[i]={cost,{w,prof}};
    }
    int W;
    cin>>W;
    cout<<fractionknap(knaps,W,n);
    return 0;
}
