// Longest Commen Subsequence of three strings

// All code is similar like LCS of two sting here the only diffence is 3d dp all for 3d

#include<bits/stdc++.h>
using namespace std;


int LCSof3 (string A, string B, string C, int n1, int n2, int n3){

    vector<vector<vector<int>>> dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,0)));
    
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            for(int k=0;k<=n3;k++){
                if(i==0 || j==0 || k==0) dp[i][j][k] = 0;
                else if(A[i-1]==B[j-1]&& B[j-1]==C[k-1]){
                    dp[i][j][k] = dp[i-1][j-1][k-1]+1;
                }
                else{
                    dp[i][j][k] = max({dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1]});
                }
            }
        }
    }
    return dp[n1][n2][n3];
}

int main(){
    cout<<LCSof3("abcdgh" ,"abcdgh","abcdgh",6,6,6)<<endl;
  return 0;
}