// Space Optimized Solution of LCS
// this problem is more optimal solution of LCS

#include<bits/stdc++.h>
using namespace std;




// Our Normal Tabulation Lcs solution look like:
int LcsTopDown(string s1,string s2,int a,int b){
    int dp[a+1][b+1];
    for(int i=0; i<=a; i++){
        for(int j=0; j<=b; j++){
            if(i==0 || j==0) dp[i][j] = 0;
            else if(s1[i-1]==s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[a][b];
     
}
           

// If we see carefully then we can realize that in each iteration we only use two rows of matrix 
// so if we use matrix of two length only then we can optimize our space
// so our solution is based on this approach

// we use binary index here to that will handle the row number

// remaining all is as it is

int LCSOptimal(string s1,string s2,int a,int b){
    int dp[2][b+1];

    bool bi;
    for(int i=0;i<=a;i++){
        bi = i & 1;
        for(int j=0;j<=b;j++){
            if(i ==0 || j == 0){
                dp[bi][j] = 0;
            }
            else if(s1[i-1]==s2[j-1]){
                dp[bi][j] = 1 + dp[1-bi][j-1];
            }
            else{
                dp[bi][j] = max(dp[1-bi][j],dp[bi][j-1]);
            }
        }
    }
        return dp[bi][b];
}

int main(){
   cout<<LCSOptimal("abcdgh" ,"abcdgh",6,6)<<endl;
  return 0;
}