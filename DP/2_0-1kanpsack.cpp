// TWO PROBLEMS In this Program
/*
1. 0-1 Knapsack problem => duplicate items not allowed => so 2D dp
2. Unbounded Knapsack   => duplicate items Allowed     => so 1D dp
*/

/*
Here what we have to do is take or not take the items in knapsack and calculate maximum profit for that 
select items according to that 
by holding the condition that sack weight should not exceed the max weight W

*/

/*
W => capacity of sack
wts[]  => weights of ith items   
vals[] => there corresponding prices  

dp[k] => max amt or profit we make if we have k is Capacity of sack

dp[w] returns max profit we can make if W is sack capacity
*/



#include<bits/stdc++.h>
using namespace std;


// 0-1 Knapsack duplicates not allowed 2D dp, row wvp and col W ===================================================================================
/*
1. 0-1 knapsack problem 
   in this problem duplicate items are not allowed so we use 2d dp
   for that our options are wt value pairs and at col we check fo all weights from 1-W+1
   so at 1st column and ist row of dp have 0
  for rest we have to calculate

*/
int ZeroOneKnapsack(int W,vector<int> vals,vector<int> wts){
  int n = vals.size();
  vector<vector<int>> dp(n+1,vector<int>(W+1));

  for(int i=0;i<vals.size()+1;i++){
    for(int j=0;j<W+1;j++){
      if(i==0 || j==0){
        dp[i][j]=0;
      }
      else{
        // if curr wt of bag is more or equal than wt of item then only take come in picture
        if(j>=wts[i-1]){
          // in take remaining wt value + curr value || cricket match if player play condition
          int take = dp[i-1][j-wts[i-1]]+vals[i-1];
          // previous value || if player not play
          int notTake = dp[i-1][j];
          dp[i][j]=max(take,notTake);
        }else{
          // else previous value
          dp[i][j] = dp[i-1][j];
        }
      }
    }
  }
  // loop for printing dp
  // for(auto row : dp){
  //   for(auto col : row){
  //     cout<<col<<" ";
  //   }
  //   cout<<endl;
  // }
  return dp[n][W];
}





// 2. unbounded knapsack ===============================================================================================================
/*
unbounded Knapsack duplicates items are allowed , 1D Dp ,row wt and col wvp
in this problem what we have to do is for every wt of pack check all the possible pairs of wt and val
in every dp
dp[i] would be max of prev dp[i] val  and dp[remaining wt] + curr vals if take
int take = dp[rem wt]+ curr[j]val here rem wt = bag wt(i) - curr wts(wts[j])
and at last return dp[w]
*/
int unboundedKnapsack(int W,vector<int> vals,vector<int> wts){

  vector<int> dp(W+1,0);

  for(int i=0;i<=W;i++){
    for(int j=0;j<vals.size();j++){
      if(i>=wts[j]){
        dp[i]=max(dp[i],dp[i-wts[j]]+vals[j]);
      }
    }
  }
  return dp[W];
}

//  W = 8
//        val[] = {10, 40, 50, 70}
//        wt[]  = {1, 3, 4, 5} 


int main(){
int W = 8;
vector<int> weight = {1,3,4,5};
vector<int> values = {10,40,50,70};
  cout<<ZeroOneKnapsack(W,values,weight);
  // cout<<unboundedKnapsack(W,values,weight);
  return 0;
}