/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
#include <ctime>
using namespace std;

int f(vector<int>&arr,int i,int j,vector<vector<int>> &dp){
    if (i==j) return 0;
    if (dp[i][j]!=-1)return dp[i][j];
    int mini = 1e9;
    for(int k=i;k<=j-1;k++){
        int steps = (arr[i-1]*arr[k]*arr[j]) + f(arr,i,k,dp) + f(arr,k+1,j,dp);
        if (steps<mini)mini = steps;
    }
    return dp[i][j] = mini;
}

int main()
{
  int n;
  cout<<"Enter number of matrices limit";
  cin>>n;
  vector<int> arr(n);
  for (int i = 0;i<n;i++){
      cin>>arr[i];
  }
  time_t start,end;
  time(&start);
  vector<vector<int>> dp(n,vector<int>(n,-1));
    int result = f(arr, 1, n - 1, dp);

    time(&end); // end time

    cout << "Minimum number of multiplications: " << result << endl;
    cout << "Time taken: " << double(end - start) << " seconds" << endl;
  
    return 0;
}
