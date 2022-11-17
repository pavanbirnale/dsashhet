// 25 Minimum number of insertion and deletion to convert string a to b
// https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1/

/*

What? : In this problem what we have to do is we have to return count of 
operations(insertion or deletion) require to convert a to b

How? : here we have given two stings a and b and we have to convet a to b 
so while conveting LCS of both the strings will be present as it is 
that mens if we proceed our solutu=ion is like this then we get our answer

first convert a ----to----> LCS ------to-------> b

covert a to lcs by deleting a.size()- lcs chars
and lcs to b by adding b.size() - lcs chars


so our final answer is :
insertions : b.size() - lcs
deletions  : a.size() - lcs
*/

 
 
#include<bits/stdc++.h>
using namespace std;
           
int MinDelAndInsert(string a,string b,int n,int m){

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
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
    return (n-dp[n][m])+(m-dp[n][m]);
}
           
int main(){
      cout<<MinDelAndInsert("geeksforgeeks","geeks",12,4);
  return 0;
}