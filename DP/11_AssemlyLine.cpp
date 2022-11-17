// Assembly Line Scheduling

// we have car manufacturing company that has several station and on each station we do something that can take time of a[i][j]
// we have to assembly line and we can choose ether of two line to manufaction our product but we need some extra time t[i][j]
// to shift  from one assembly line to another 
// by this way manufaction our product with minimum time and return it
 

/*
THis is one of the pep coding approach to find next answer by selecting previous result
at this time you dont exactly rember the type
that contains 
house robber
building bridges etc
*/

// here what we does initially add the exit time to last cells of dp
// then traverse loop from last pos ... see in code
 
#include<bits/stdc++.h>
using namespace std;
           
int AssemblyLine(int n,int a[][4],int t[][4],pair<int,int> entry , pair<int,int>exit){
     int dp[2][n];
     dp[0][n-1] = exit.first + a[0][n-1];
     dp[1][n-1] = exit.second + a[1][n-1];

     for(int i=n-2;i>=0;i--){
        //  dp:
        // 25 21 16 20 
        // 23 22 12 11 
        // calculating curr result from same assembly line or changing line and adding the time to it and then min of them
         dp[0][i] = min(dp[0][i+1],dp[1][i+1]+t[1][i]) + a[0][i];
         dp[1][i] = min(dp[1][i+1],dp[0][i+1]+t[0][i]) + a[1][i];
     }
    //  for(int i=0;i<n;i++){
    //      cout<<dp[0][i]<<" ";
    //  }
    //  cout<<endl;
    //    for(int i=0;i<n;i++){
    //      cout<<dp[1][i]<<" ";
    //  }
    //  cout<<endl;
    //  adding the entry time
     return min(dp[0][0]+entry.first,dp[1][0]+entry.second);
}
           
int main(){
    int a[2][4] = {{4, 5, 3, 2},{2, 10, 1, 4}}; 
    int t[2][4] = {{0, 7, 4, 5},{0, 9, 2, 8}}; 
    pair<int,int> e = {10, 12};
    pair<int,int> ex = {18, 7}; 
    int n = 4;      
    cout<<AssemblyLine(n,a,t,e,ex);
  return 0;
}