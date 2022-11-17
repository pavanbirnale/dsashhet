//  Count number of ways to partition a set into k subsets
// NODSBOG : https://www.geeksforgeeks.org/count-number-of-ways-to-partition-a-set-into-k-subsets/

/*
// gfg
Approach: Firstly, let’s define a recursive solution to find the solution for nth element. There are two cases. 
1. The previous n – 1 elements are divided into k partitions, i.e S(n-1, k) ways. Put this nth element into one of the previous k partitions. 
So, count = k * S(n-1, k)
if friends are 123 i.e n=3;
then for first term = g 

2. The previous n – 1 elements are divided into k – 1 partitions, i.e S(n-1, k-1) ways. Put the nth element into a new partition ( single element partition).So, count = S(n-1, k-1)
3. Total count = k * S(n-1, k) + S(n-1, k-1).
*/
 
#include<bits/stdc++.h>
using namespace std;

//Naive Approach :  Recursive approach TC : O(2^N); SC : O(N) (call stack space)
int  kSubsetPartitionNaive(int n,int k){
     
    //  if number of friends reach to zero or k teams get zero of k teams greater than firends then return zero
     if(n==0 || k==0 || k>n ) return 0;

    //  if team is only one or to part into singal partition or teams equal to friends then oly single partition happed that is all goes in single team
     if(k==1 || k==n) return 1;

    //  else  for all rest
     return k*kSubsetPartitionNaive(n-1,k)+kSubsetPartitionNaive(n-1,k-1);
}

/*             DP Table               

              k->  subset count / teams Count 
        0   1   2   3   4
f   0   0   0   0   0   0
r   1   0   1   as
i   2   0       follows
e   3   0
n   4   0
d
s

^
|
K


*/

// Optimal Tabulation Dp : TC : O(N*K) ; SC : O(N*K)
int  kSubsetPartitionOptimal(int n,int k){

    vector<vector<int>>dp(n+1,vector<int>(k+1,0));

    //  for 1st row we cant partition the 0 frient in to any k teams
    for(int i=0;i<k;i++){
        dp[0][i] = 0;
    }

    // for fist column we cant partion n friends into 0 teams
    for(int i=0;i<k;i++){
        dp[i][0] = 0;
    }

// for rest of sets
    for( int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(i==1 || j==1)
            dp[i][j]=1;
            else
            dp[i][j] = j*dp[i][j-1] + dp[i-1][j-1];
        }
    }
    return dp[n][k];
}
           
int main(){
    //   cout<<kSubsetPartitionNaive(3,2);
      cout<<kSubsetPartitionOptimal(3,2);
  return 0;
}