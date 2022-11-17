// Minimum sum partition
// Hard Tagged on GFG
// this  problem is variation of target Sum subset and partition subset Sum
// specially of subset sum partition because in partition subset sum we have to find two subset that have equal sum
//  and in this problem we have to find two subset that has minimum partition sum difference

// so like in equal subset partition we only findone subset and remaning subset will present in arr
//  i.e what we have to do  find set s1 , and set s2 and find there absolute difference of sum of subset elements
//  that should be minimum 
//  abs(s1-s2) = diff


/*
Algorithm : 
1. find sum of given array that would be the maximum diff of partition ie. s1 = {empty} and s2 = {whole array}
2. create dp of array size +1 & sum+1;
3.here j ( col) in dp holds value from 1 to sum+1 which are the sums of all the possible subsets
so last row of dp with true value would be possible sums of subsets
but here we only think for half row due to we only consider about singal subset

s1-s2 = diff
s1-(sum-s1) = diff       -----(s1+s2=sum);
diff = abs(sum - 2*s1);
ans = min(ans,diff);
*/

 
 
#include<bits/stdc++.h>
using namespace std;
           
int minDifference(int arr[], int n)  {
    if(n==1) return arr[0];
    long long sum = 0;
    // finding sum
    sum = accumulate(arr,arr+n,sum);
    
    vector<vector<bool>> dp(n+1,vector<bool>(sum+1));
    
    // creating dp
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            if(i==0&& j==0) dp[i][j] = 1;
            
            else if(i==0) dp[i][j] = 0;
            else if(j==0) dp[i][j] = 1;
            else{
                // not bated
                if(dp[i-1][j]==1) dp[i][j]=1;
                else{
                    int val = arr[i-1];
                    if(j>=val){
                        if(dp[i-1][j-val]==1) dp[i][j] = 1;
                    }
                }
            }
        }
    }
    long long minD = INT_MAX;

    // s1-s2 = diff
    // s1-(sum-s1) = diff       -----(s1+s2=sum);
    // diff = abs(sum - 2*s1);
    // ans = min(ans,diff);

//  here we only check untill half of dp
    for(int i=1;i<=dp[0].size()/2;i++){
        if(dp[n][i]==1){
        long long temp = abs(sum-2*i);
        minD=min(minD,temp);
        }
    }
    return minD;
} 
           
int main(){
      f();
  return 0;
}