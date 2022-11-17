// count subset sum || count the subsets with given sum
// In target sum || Subset sum we only return whether the subset of sum is present in arr or not
//  but in thin problem we have to return the count of subsets

// code is very simple the only thing can change is in last we check that either one should have to true
//  but here we have to add both the dp[i-1][j] and dp[i-1][j-arr[i-1]];

//  zeroes condition separately handled
 
#include<bits/stdc++.h>
using namespace std;
           
long long M = 1e9+7;
int perfectSum(int arr[], int n, int sum)
{
    int countZero=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            countZero++;
        }
    }
    
    vector<vector<long long>> dp(n+1,vector<long long>(sum+1,0));
    
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            
            if(i==0 && j==0) dp[i][j]=1;
            
            else if(i==0) dp[i][j] = 0;
            
            else if(j==0) dp[i][j] = 1;
            
            else{
                int val = arr[i-1];
                if(j>=val && arr[i-1]!=0){
                    // here is the change
                    dp[i][j] = (dp[i-1][j]%M+dp[i-1][j-val]%M)%M;
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    int c = pow(2,countZero);
    return dp[n][sum]*c;
}
    
           
int main(){
      f();
  return 0;
}