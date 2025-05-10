/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
#include <ctime>
using namespace std;

int f(vector<int> &arr,vector<int> &profit,int W,int ind,vector<vector<int>> &dp){
    if (ind==0 || W==0){
        return 0;
    }
    if (dp[ind][W]!=-1){
        return dp[ind][W];
    }
    int notTake = f(arr,profit,W,ind-1,dp);
    int take = 0;
    if (arr[ind]<=W){
        take = profit[ind]+f(arr,profit,W-arr[ind],ind-1,dp);
    }
    return dp[ind][W]= max(take,notTake);
}

int main()
{
  int n;
  cout<<"Enter number of  elements";
  cin>>n;
  vector<int> arr(n);
  for (int i = 0;i<n;i++){
      cin>>arr[i];
  }
  vector <int> profit(n);
  for (int i = 0;i<n;i++){
      cin>>profit[i];
  }
  int W;
  cout<<"Enter The weight";
  cin>>W;
  time_t start,end;
  time(&start);
  vector<vector<int>> dp(n,vector<int>(W+1,0));
for (int i = arr[0]; i <= W; i++) {
        dp[0][i] = profit[0];
    }
  for(int i=1;i<n;i++){
      for (int j=0;j<=W;j++){
          int nott=dp[i-1][j];
          int take=0;
          if (arr[i]<=j){
              take = profit[i]+dp[i-1][j-arr[i]];
          }
          dp[i][j]=max(take,nott);
      }
  }
//   cout<<f(arr,profit,W,n-1,dp);
    int result= dp[n-1][W];
        time(&end); // end time

    cout << "Max Weight Possible: " << result << endl;
    cout << "Time taken: " << double(end - start) << " seconds" << endl;
  return 0;
}
