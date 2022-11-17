// climbing stairs with jump
// tabulation 
#include<bits/stdc++.h>
using namespace std;

int climbingStairsJump(int jumps[] , int n){
   vector<int> dp(n+1,0);
    dp[n] = 1;

    for(int i = n -1 ;i>=0;i--){
        for(int j=1;j<=jumps[i] && i+j<n+1;j++){
            dp[i] += dp[i+j];
        }
    }
    return dp[0];
}
int main(){
    int jump[13] = {5,5,2,4,1,5,9,8,6,3,8,9,1};
    cout<<climbingStairsJump(jump,13);
  return 0;
}