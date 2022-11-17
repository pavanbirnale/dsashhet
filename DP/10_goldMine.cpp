// Gold Mine Problem

// prerequisite maze path sum : https://leetcode.com/problems/minimum-path-sum/
// in above problem we only check next and below cell to get min
//  but in goldmine we check to right ,right - up and right down possition to get max sum
// and also in goldmine we have to move from col 0 to col n-1 and return max gold collected

// Approach :  dp tabulation
/*
1.Step storage 
we can create dp and matrix size and set all elem to -1;

2.step direction
as smaller problem is at n-1 m-1 position we we use bottom up approach to solve 

3.procced : 
we have to traverse column wise from m-1 to 0 and build solution as we need next three position to get maximum ans
and at last return max of colum 1 which is an answer
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
     {
        //  edge case for single row
         if(n==1){
             int ans=0;
             for(int i=0;i<m;i++) ans+=M[0][i];
             return ans;
         }
        //   rest of cases
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int mtn=INT_MIN;
        // traver from last column
        for(int j=M[0].size()-1;j>=0;j--){
            for(int i=M.size()-1;i>=0;i--){
                // if col is last then user input matrix to set value sin dp
                if(j==M[0].size()-1){
                    dp[i][j]=M[i][j];
                }
                // if 1st row then we cant check up right cell
                else if(i==0){
                    dp[i][j]=max(dp[i][j+1],dp[i+1][j+1])+M[i][j];
                }
                // if row is last then we cant check right down cell
                else if(i==M.size()-1){
                    dp[i][j]=max(dp[i][j+1],dp[i-1][j+1])+M[i][j];
                }
                // for rest of cell check all three directions
                else{
                    dp[i][j]=max({dp[i][j+1],dp[i-1][j+1],dp[i+1][j+1]})+M[i][j];
                }
                mtn=max(mtn,dp[i][j]);
            }
        }
        return mtn;
    }
};

           
int main(){
          
  return 0;
}