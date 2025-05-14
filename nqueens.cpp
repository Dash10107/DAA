#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int x[100];
int place(int k,int i){
    for(int j=0;j<k;j++){
        if (x[j]==i || abs(x[j]-i)==abs(j-k))
        return 0;
    }
    return 1;
}
void printboard(int n){
    for (int i = 1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (x[i]==j)cout<<"Q ";
            else cout<<'.';
        }
        cout<<endl;
    }
    cout<<endl;
}
void nqueens(int k,int n){
    for(int i = 1;i<=n;i++){
        if (place(k,i)){
            x[k]=i;
            if(k==n){
                printboard(n);
            }
            else{
                nqueens(k+1,n);
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    nqueens(1,n);
    return 0;
}
