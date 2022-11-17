// 26 Longest Palindromic Subsequence

/*
What? . In this problem we have given one single string a and we have to return the count of 
longest palindromic subsequence


How? . for lcs we need two strings if we derived second string by reversing a and then take 
lcs of them then that lcs would be our longest palindromic subsequence
*/

 
 
#include<bits/stdc++.h>
using namespace std;
           
int LongestPalSeq(string a){
    int n = a.size();
    string b = string(a.rbegin(),a.rend());
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(a[i-1]==b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}
           
int main(){
      cout<<LongestPalSeq("bbabcbcab");
  return 0;
}