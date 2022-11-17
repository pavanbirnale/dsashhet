// climb stairs with max 3 jumps
//#dp
#include<bits/stdc++.h>
using namespace std;

// Memoization Dp
int climbStairsMemo(int n,int dp[]){
    if(n==0) return 1;
    if(n<0) return 0;

    if(dp[n]!=-1) return dp[n];
    cout<<"hello"<<n<<endl;
    int jumpCountTillm1 = climbStairsMemo(n-1,dp);
    int jumpCountTillm2 = climbStairsMemo(n-2,dp);
    int jumpCountTillm3 = climbStairsMemo(n-3,dp);

    return dp[n] = jumpCountTillm1 + jumpCountTillm3 +jumpCountTillm2;
}

// Tabulation Dp

int climbStairsTab(int n){
    vector<int> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3;i<n+1;i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp[n];
}
int main(){
    int dp[7];
    memset(dp,-1,sizeof(dp));
    // cout<<climbStairsMemo(6,dp);
    cout<<climbStairsTab(6);
  return 0;
}