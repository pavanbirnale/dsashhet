// climb stairs with minimum moves

// here in this problem what we have to do is tomove from sorce to destintion with minimum number of jumps
// / for that we use tabulation dp ( bottom up approch)

#include<bits/stdc++.h>
using namespace std;
int ClinbStairsMinJump(vector<int> jumps,int n){

  vector<int> dp(n+1,-1);
  dp[n]=0;

  for(int i=n-1;i>=0;i--){
    // if jump is not possible from that possition then not enter 
    if(jumps[i]>0){
      // get miminum move from all possible i+kj possition
    int mi = INT_MAX;
    for(int j=1;j<=jumps[i] && i+j < n+1;j++){
      // if jump not possible that mense in i+jth pos in jupms arr was 0 
      if(dp[i+j]!=-1){
        mi=min(mi,dp[i+j]);
      }
    }
    // set min move from i to dp [i]
    if(mi != INT_MAX){
      dp[i]=mi+1;
    }
  }
  }
  // for(int i=0;i<n+1;i++){
  //   cout<<dp[i]<<" ";
  // }
return dp[0];
}
           
int main(){
    vector<int> jump = {1,1,1,4,9,8,1,1,10,1};
    cout<<ClinbStairsMinJump(jump,10);
  return 0;
}