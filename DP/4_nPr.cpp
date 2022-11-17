// Permutation Coefficient

/*
Formule : 
1). Permutation Coefficient - 
    nPr = n!/(n-r)!

    P(n, k) = k * P(n-1, k-1) + P(n-1, k)
    P(n, 0) = P(n, n) = 1

*/

 
 
#include<bits/stdc++.h>
using namespace std;
           
// 3. Direct memoisation (See nCr for more)
int nPr(int n,int r){

    vector<vector<int>> dp(101,vector<int>(101,-1));

    for(int i=0;i<=n;i++){
        for(int j=0;j<=min(n,r);j++){
            if(j==0){
                return 1;
            }
            else{
                dp[i][j] = j*dp[i-1][j-1] * dp[i-1][j];
            }
        }
    }
return dp[n][r];
}
// 4). By using factorial

int nPrFact(int n,int r){
    int dp[n+1];
    dp[0] = 1;
    for(int i=1;i<n;i++){
        dp[i] = i*dp[i-1];
    }
    return dp[n]/dp[n-r];
}
           
int main(){
      f();
  return 0;
}