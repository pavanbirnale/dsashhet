//29. Longest Repeating Subsequence

/*
What ?. we have given single string A and we have to find the longest repeating subsequence from string A
eg. AABCCEED    ans -> ACE
*/

/*
How ?. As from from observation of que and answer we can say that only the duplicate element are present
int answer and they are only single 

in other words we can take same dtring for second ie. string A = AABCCEED and string B also AABCCEED
so if the chars present only ones in both the string at same index then that not take part in answer
if the cross pairing between the chars is happened then only that chars came in answer
 here cross pairing mens both the chars at i and j are same but the index i and j are not same


 only i!=j adds in LCS code
*/
 
 
#include<bits/stdc++.h>
using namespace std;
           
int LRS(string a){
     string b = a;
     int n = a.size();
     int m = b.size();
     vector<vector<int>> dp(n+1,vector<int>(m+1,0));

     for(int i=0;i<=n;i++){
         for(int j=0;j<=m;j++){
             
             if(i==0 || j==0) dp[i][j] = 0;
            //  only && condition changes
             else if(a[i-1]==b[j-1] && i!=j){
                 dp[i][j] = dp[i-1][j-1] + 1;
             }
             else{
                 dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
             }
         }
     }
     return dp[n][m];
}
           
int main(){
      cout<<LRS("AABCCEDD");
  return 0;
}