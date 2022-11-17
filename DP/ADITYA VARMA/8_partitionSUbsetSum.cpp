// Partition Equal Subset Sum 
// This problem is in Backtracking as well as in dp in DSASHEET but it is solved by DP

// Variation of target Sum subset

/*
Algorithm: 
This problem is variation of target sum Subset /oneday match
this this problem what we have to do is first of all calculate sum of array and if sum is odd the return false as we not divided that array to equal parts
so as the problem states that the array should have to participate in two subsets so all the array elements are divided into two parts
so problem is now divided into sub problem that we only have to find one subset whose sum is half of array sum if such subset is present the another subset is also present 

so we only need to write code of target sum subset
*/
 
 
#include<bits/stdc++.h>
using namespace std;
           
int equalPartition(int N, int arr[])
    {
     long long sum=0;
    //  stl function to calculate sum of whole array
      sum = accumulate(arr, arr+N, sum);

    //  check is sum is odd or even
      if(sum%2==1) return 0;
      
    //   now our target is 
      long long target = sum/2;
      vector<vector<bool>> dp(N+1,vector<bool>(target+1));
      for(int i=0;i<dp.size();i++){
          for(int j=0;j<dp[0].size();j++){

             // first cell
            if(i==0 && j== 0){
                dp[i][j] = true;
            }
            // first row
            else if(i==0){
                dp[i][j] = false;
            }
            // first column
            else if(j==0){
                dp[i][j] = true;
            }
           // rest of cell
              else{
                  if(dp[i-1][j]== 1) dp[i][j]=1;
                  else{
                      int val = arr[i-1];
                      if(j>=val){
                          if(dp[i-1][j-val]) dp[i][j]=1;
                      }
                  }
              }
          }
      }
      return dp[N][target];
    }
           
int main(){
      f();
  return 0;
}