// 30. Subsequence Patten Maching

/*
What ?. In this question we have given two string A,B and we have to tell that weather string A in present
as a subsequence in string b

Subsequence means : ordered set of charector that are may or may not in continues fastion
Substring means   : ordered set of charector in continues fastion


how ?. if Lcs of both strings is string A itself then that subsequence pattent is present in string b
then we return 1;
*/

 
 
#include<bits/stdc++.h>
using namespace std;
           
bool subSeqPatMach(string pat,string str){
     int n = pat.size();
     int m = str.size();
     vector<vector<int>> dp(n+1,vector<int>(m+1,0));

     for(int i=0;i<=n;i++){
         for(int j=0;j<=m;j++){
             if(i==0 || j==0){
                 dp[i][j] = 0;
             }
             else if(pat[i-1]==str[j-1]){
                 dp[i][j] = dp[i-1][j-1] + 1;
             }
             else{
                 dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
             }
         }
     }
     return n==dp[n][m];
}
           
int main(){
    cout<<subSeqPatMach("ABCD","ACCBDDC");
  return 0;
}