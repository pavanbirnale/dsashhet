// Longest Commen Subsequence

/*
This Problems has more than 15+ variation problems this are -



*/

/*
We Can all the approches for this problem that mens :
1). Recursive Approach
2). Memoization (Bottom Up)
3). Tabulation (Top Down) 
*/

/*
Format Of Recursive Approach : 

returnType functionName(variable Parameters){
    base case

}
*/
#include<bits/stdc++.h>
using namespace std;

// 1st  Recursive Code 
int LcsRecursive(string s1,string s2,int a,int b){

    if(a==0 || b==0) return 0;

    if(s1[a-1]==s2[b-1]){
        return 1+LcsRecursive(s1,s2,a-1,b-1);
    }
    else{
        return max(LcsRecursive(s1,s2,a-1,b),LcsRecursive(s1,s2,a,b-1));
    }
}


// 2nd Memoization (Bottom Up)
int LcsMemo(string s1,string s2,int a,int b,vector<vector<int>> dp){

    if(a==0 || b==0) return 0;
    if(dp[a][b]!=-1) return dp[a][b];
    if(s1[a-1]==s2[b-1]){
        return dp[a][b] = 1+LcsMemo(s1,s2,a-1,b-1,dp);
    }
    else{
        return dp[a][b] = max(LcsMemo(s1,s2,a-1,b,dp),LcsMemo(s1,s2,a,b-1,dp));
    }
}


// 3rd Tabulation (Top Down)
int LcsTopDown(string s1,string s2,int a,int b){
    int dp[a+1][b+1];
    memset(dp,-1,sizeof(dp));

    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            if(i==0 || j==0) dp[i][j] = 0;
            else if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else{
                dp[i][j] = max(dp[i-1][j] ,dp[i][j-1]);
            }
        }
    }
return dp[a][b];
}

int main(){
vector<vector<int>> dp(101,vector<int>(101,-1));
    cout<<LcsRecursive("abcdgh" ,"abcdgh",6,6)<<endl;
    cout<<LcsMemo("abcdgh" ,"abcdgh",6,6,dp)<<endl;
    cout<<LcsTopDown("abcdgh" ,"abcdgh",6,6)<<endl;
  return 0;
}