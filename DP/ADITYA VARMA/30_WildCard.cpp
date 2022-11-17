// Wild Card || not present in Aditya Varma Dp Series || done separately by pepcoding video
// Wildcard Pattern Matching

// Present in DsaSheet String 

// Important Problem

/*
What ?. we have given a pattern with chars, * and ? we have return weather wildcard pattern can
mached with string or not

In pattern 
1). ? must be replace with any chars
2). * can or can not be replace with any char 
    that means * can replace with 0- infinity chars

After replacing like return weather we can achieve the string or not
*/

 
/*
This is not LCS like approach

we use Bottom up dp as small problem is at last cell

How ?.
for building dp : 
if char at pattern is :
1. any char a to z   => if(char of pat == char of str) then see diagonally for remaining string
                        else if not mached then set false
2. ?  => see only at diagonally down and get that result
3. *  => then we have two options
         i). check for all th cell of down column untill end and check weather any cell has true result
         ii). or simply check right cell and down cell as right cell is always made from down row
*/

 
 
#include<bits/stdc++.h>
using namespace std;
           
bool wildCard(string pat , string str){
    int n = pat.size();
    int m = str.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i=n;i>=0;i--){
        for(int j=m;j>=0;j--){

            // last cell
            if(i==n && j==m){
                dp[i][j] = 1;
            }
            // last row
            else if(i==n){
                dp[i][j] = 0;
            }
            // last column here another condition is present if pat[i]=='*' then check for below cell result
            else if(j==m){
                if(pat[i] == '*'){
                    dp[i][j] = dp[i+1][j];
                }
                else{
                    dp[i][j] = false;
                }
            }
            else{
                // if same chars then check for remaining string in diagonal
                if(pat[i]==str[i]){
                    dp[i][j] = dp[i+1][j+1];
                }
                // check only in diagonal
                else if(pat[i]=='?'){
                    dp[i][j] = dp[i+1][j+1];
                }
                // check for right and down cell
                else if(pat[i]=='*'){
                    dp[i][j] = dp[i][j+1] || dp[i+1][j];
                }
                // both pat of i and str i are different chars thenreturn 0;
                else{
                    dp[i][j] = 0;
                }
            }
        }
    }
    return dp[0][0];
}
           
int main(){
      cout<<wildCard("a*ab","baaabab");
  return 0;
}