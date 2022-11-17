// Count all subsequences having product less than K

/*
Algorithm : 
create dp dp[k+1][n+1] where dp[i][j] shows that how many seq untill j-th terms of array which can form product less than i;
if we know the count of subseq untill j-1 then we can calculate result for jth term and add up them gives result for curr i and j th term.
*/
 
#include<bits/stdc++.h>
using namespace std;
           
int CountSubseqProdLessThanK(vector<int> arr,int k){
     int n = arr.size();
    // create dp : dp[k+1][n+1] where dp[i][j] shows that how many seq untill j-th terms of array which can form product less than i;
    int dp[k+1][n+1];
    memset(dp,0,sizeof(dp));

    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(i==0 || j==0) dp[i][j] = 0;
            else{
                // we know that i represent k so if curr arr elem that is arr[j-1] if it is greater than i then such arr elem
                //  doesn't form and product less than k
                if(arr[j-1]<=i){
                    dp[i][j] = dp[i][j-1] + dp[i/arr[j-1]][j-1] + 1;
                }
                else{
                    // if the arr elem is greter than i then prev j-1 terms count is continued
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
    }
    return dp[k][n];
}
           
int main(){
    vector<int> arr = {1,2,3,4}; 
    cout<<CountSubseqProdLessThanK(arr,10);
  return 0;
}