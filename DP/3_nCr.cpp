// nCr
// Binomial Coefficient

/*

A binomial coefficient C(n, k) also gives the number of ways, disregarding order, that k 
objects can be chosen from among n objects more formally, the number of k-element 
subsets (or k-combinations) of a n-element set.

Formule : 
1). Binomial Coefficient - 
    nCr = n!/(r!*(n-r)!)

    C(n, k) = C(n-1, k-1) + C(n-1, k)
    C(n, 0) = C(n, n) = 1

*/

#include<bits/stdc++.h>
using namespace std;
           
// 1). Recursive Code
int nCrRecursive(int n,int r){
    if(r>n) return 0;
    if(r == 0 || r == n) return 1;
    return nCrRecursive(n-1 , r-1) + nCrRecursive(n-1 , r );
}


// 2). Tabulation - Bottom Up
int dp[101][101];
int nCrBottomUp(int n,int r){
    if(dp[n][r] != -1) return dp[n][k];
    if(r==0 || r==n){
        dp[n][r] = 1;
        return dp[n][r];
    }
    return dp[n][r] = nCrBottomUp(n-1,r-1) + nCrBottomUp(n-1,r);
}


// 3). Memoization - Top Down
int nCrMemo(int n,int r){
    if(r>n) return 0;

    vector<vector<int>> dp(101,vector<int>(101,-1));
    for(int i=0i<=n;i++){
        for(int j=0;j<=min(r,n);j++){
            if(j==0 || j==i) dp[i][j]=1;
            else{
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }
    }
    return dp[n][r];
}
int main(){
      f();
  return 0;
}
