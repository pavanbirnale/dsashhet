// Get Minimum Squares || Perfect Squares || Find the minimum number of squares of any number that sums to N

/*
This Problem is also an application of  LIS in this we check for all th perfect square value from 1 to i in rem variable
*/

 /*
This problems are come in singal group : 

Group 5 : Longest Incressing subsequence (LIS)
1. Longest Incresing Subsequence
2. Maximum Sum Incresing Subsequence
3. Longest Bitonic Subsequences
4. Maximum non Overlaping bridges
5. Russian Doll Problem
6. Perfect Squares
*/
 
#include<bits/stdc++.h>
using namespace std;
           
int minSquare(int n){

    vector<int> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2;i<=n;i++){
        int mi = INT_MAX;
        for(int j=1;j*j<=i;j++){
            int rem = i-j*j;
            mi = min(mi,dp[rem]);
        }
        dp[i] = mi+1;
    }
    return dp[n];
}
           
int main(){
      cout<<minSquare(5);
  return 0;
}