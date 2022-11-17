// Longest subsequence such that difference between adjacents is one

// read article
//  https://www.geeksforgeeks.org/longest-subsequence-such-that-difference-between-adjacents-is-one/
 
#include<bits/stdc++.h>
using namespace std;
           
int LSWDiffOne(vector<int> arr){
    int n = arr.size()+1;
     int dp[n];
     memset(dp,1,sizeof(dp));

            // handnling case of dulpicate
            set<int> st;
            for(int i=0;i<n;i++) st.insert(arr[i]);
            if(st.size()==1) return 1;

     int ans = INT_MIN;
     for(int i=0;i<n;i++){
         for(int j=0;j<i;j++){
             if(arr[i]==arr[j]+1 || arr[i]==arr[j]-1){
                 dp[i] = max(dp[i],dp[j]+1);
                 ans = max(ans,dp[i]);
             }
         }
     }
     return ans;
}
           
int main(){
      f();
  return 0;
}