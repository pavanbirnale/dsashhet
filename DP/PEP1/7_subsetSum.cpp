// Subset sum || target sum subset
// Subset Sum Problem : https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/
// in dsa sheet different problem is given

// below problems are come in one categary

/*
1. Subset sum || target sum subset
2. Coin Change combinations
3. Coin Change permutation
4. coin change problem
5. 0-1 knapsack
6. unbounded knapsack
*/

#include<bits/stdc++.h>
using namespace std;

bool isSubsetSum(vector<int> arr,int sum){
int n=arr.size();
// create vector of n+1 and sum+1
vector<vector<bool>> dp(n+1,vector<bool>(sum+1,0));

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
        // batting nahi kar raha
        if(dp[i-1][j]==true){
            dp[i][j] = true;
        }
        else{
            // bating kar raha
            int val = arr[i-1];
            if(j>=val){
                if(dp[i-1][j-val]==true) dp[i][j]=true;
            }

        }
    }
}
}
return dp[n][sum];
}
int main(){
          
  return 0;
}