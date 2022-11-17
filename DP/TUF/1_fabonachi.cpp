#include<bits/stdc++.h>
using namespace std;

// 1 . simple code 
int fib1(int n){
if(n==0) return 0;
if(n==1) return 1;

    int fnm1 = fib1(n-1);
    int fnm2 = fib1(n-2);

    return fnm1 +fnm2;
}

// 2. syntax changed in code 1 (pepcoding syntax)
int fib2(int n){
    if(n==0 || n==1) return n;
    return fib2(n-1)+fib2(n-2);
}

// 3. dp code
int dpfib(int n,vector<int> &dp){
    if(n==0 || n==1) return n;

    if(dp[n]!=-1) return dp[n];

    return dp[n] = dpfib(n-1,dp)+dpfib(n-2,dp);
}

// 4. iterative dp (Tabulation)
int itrDp(int n){
    vector<int> dp(n+1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

// 5. fully optimal SC : O(1)
int fibOptimal(int n){

    int pm1 = 0;
    int pm2 = 1;
    for(int i = 2;i<=n+1;i++){
        int curr = pm1+pm2;
        pm2 = pm1;
        pm1 = curr;
    }
    return pm1;
}
int main(){
    vector<int> dp(11,-1);
    // cout<<dpfib(10,dp);
    cout<<fibOptimal(10);
  return 0;
}