// Maximum Length Chain of Pairs

// This problemis Variation of Longest Increasing subsequence

// same as LIS only here change is rather than comparing the direct value comare the elements in pair
 
 
#include<bits/stdc++.h>
using namespace std;
           
int maxLenPair(vector<vector<int>> pairs){
    int n = pairs.size();
     vector<int> dp(n,1);
     int omax = 0;
     for(int i=1;i<n;i++){
         int ma = 0;
         for(int j=0;i<i;j++){
             if(pairs[i][0]>pairs[j][1]){
                 ma = max(ma,dp[j])
             }
         }
         dp[i] = ma+1;
         omax = max(omax,dp[i]);
     }
     return omax;
}
           
int main(){
      f();
  return 0;
}