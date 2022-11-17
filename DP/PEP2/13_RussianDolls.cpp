// Russian Doll envelopes
// https://leetcode.com/problems/russian-doll-envelopes/

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
           
int maxEnvelop(vector<vector<int>> envelopes,int n){
     
     sort(envelopes.begin(),envelopes.end());

     vector<int> dp(n);

     int omax=0;
     for(int i=0;i<n;i++){
         int ma =0;
         for(int j=0;j<i;j++){
            //  although we sort width but it may be same so again check one more time here
             if(envelopes[j][1]<envelopes[i][1] && envelopes[j][0]<envelopes[i][0] && dp[j] > ma ){
                 ma = dp[j];
             }
         }
         dp[i] = ma + 1;
         omax = max(omax, dp[i]);
     }
     return omax;
}
           
int main(){
      maxEnvelop();
  return 0;
}