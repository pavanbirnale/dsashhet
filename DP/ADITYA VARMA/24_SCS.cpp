// Shortest Common Supersequence

/*
In this problem what we have to do is to create new supersequence in which both 
the a and b present as Lcs and length of supersequence is minimum
*/

/*
Algo :  This problem is variation of LCS so, 
at worst case answer should be concatenation of both the strings  ie. ans = a.size() + b.size()

but as we know than LCS of two strings are largest sequential charectors of both the strings
so this lcs is common in both the strings so if we can subtract one lcs from sum of lengths of a and b 
then we get our answer
*/
#include<bits/stdc++.h>
using namespace std;
           
int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i == 0 || j == 0) dp[i][j] = 0;
                else if(X[i-1] == Y[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1; 
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        // only this line is changed
        return (m+n) - dp[m][n];
    }
           
int main(){
      f();
  return 0;
}