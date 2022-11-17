// 27 Minimum number of deletion to convert a string to palindrome

/*
What ? : In this problem what we have to do is we have
to return count of minimum number of deletion from a string A to convert it to palindromic string

How ? : so first of all we think reversals that after deleting the some chars the string would be the 
longest palindromic subsequence of given string

that mens if we find the longest palindromic subsequence of the given string and subtract the length 
of lcs from input string size then that would be our answer



// IMP
and as rather than finding minimum number of deletion to convert string to palindrome 
find some deletion to convert stirng to Longest palindromic subsequence

as Number of deletions are inversely proportional to length of LPS
as the deletion incresses the length of LPS decreases
*/

 
 
#include<bits/stdc++.h>
using namespace std;
           
int MinDel2Pal(stirng a){
    string b = string(a.rbegin(),a.rend());
    int n = a.size();

    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return n-dp[n][n];
}
           
int main(){
      MinDel2Pal("");
  return 0;
}