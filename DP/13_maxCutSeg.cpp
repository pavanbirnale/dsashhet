// Maximize The Cut Segments
// Solution by code library

// Problem : 
// Given an integer N denoting the Length of a line segment. 
// You need to cut the line segment in such a way that the cut length of a line segment 
// each time is either x , y or z. Here x, y, and z are integers.
// After performing all the cut operations, your total number of cut segments must be maximum.

/*
Algo : 
Simple Problem 
Blindly pass the recution for all x,y and z and take max of them that will be be the max count
*/



 
 
#include<bits/stdc++.h>
using namespace std;
int dp[101];

int solve(int n,int x,int y,int z){
// base case if seg become zero then return 0;
if(n==0) return 0;
if(dp[n]!=-1) return dp[n];

// initialize a,b,c with min value
int a,b,c;
a=b=c=INT_MIN;


// pass recurion for all x,y,z if the are less than n due tto negative result
if(n>=x) a = solve(n-x,x,y,z);
if(n>=y) b = solve(n-y,x,y,z);
if(n>=z) c = solve(n-z,x,y,z);

// and at last find max of then and return plus 1
return dp[n] = 1 + max({a,b,c});
}

int maxCutingSeg(int n,int x,int y,int z){
     memset(dp,-1,sizeof(dp));
     int ans = solve(n,x,y,z);
    //  if it return sumthing negative then return 0
     return ans<0 ? 0 : ans;
}
           
int main(){
      cout<<maxCutingSeg(4,2,1,1);
  return 0;
}