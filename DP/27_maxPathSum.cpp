// Min Cost PathProblem
// Reverse Goldmine

/*
This proble is very semilar to goldmine problem in gold mine we collect gold from first row to last row
and in this problem we have to calculate max sum from top to bottom


as the both problem are solved in reverse direction (Bottom Up) because smallest proble is at destination
*/
 
 
#include<bits/stdc++.h>
using namespace std;
           
int maximumPath(int n, vector<vector<int>> Matrix)
    {

        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i == n-1){
                    dp[i][j] = Matrix[i][j];
                }
                else if(j==0){
                    dp[i][j] = max(dp[i+1][j],dp[i+1][j+1]) + Matrix[i][j];
                }
                else if(j==n-1){
                    dp[i][j] = max(dp[i+1][j],dp[i+1][j-1]) + Matrix[i][j];
                }
                else {
                    dp[i][j] = max({dp[i+1][j],dp[i+1][j-1],dp[i+1][j+1]})+ Matrix[i][j];
                }
            }
        }
        int ma = INT_MIN;
        for(auto i : dp[0]){
            ma=max(ma,i);
        }
        return ma;
    }

           
int main(){
      f();
  return 0;
}