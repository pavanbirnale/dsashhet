// Maximum Sum Increasing Subsequence

// very Similar problem to Longest incresing subsequence only diff is that rahter than storing length of LIS to dp 
// store sum 



/*
This problems are come in singal group : 

Group 5 : Longest Incressing subsequence (LIS)
1. Longest Incresing Subsequence
2. Maximum Sum Incresing Subsequence
3. Longest Bitonic Subsequences
4. Maximum non Overlaping bridges
5. Russian Doll Problem

*/



 
 
#include<bits/stdc++.h>
using namespace std;
           
int maxSumIS(int arr[], int n)  
{  
    vector<int> dp(n);
    int omax=0;
    for(int i=0;i<n;i++){
        int ma = 0;
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i] && dp[j]>ma){
                ma=dp[j];
            }
        }
        
        // Difference is in this line only from LIS 
        dp[i] = ma+arr[i];
        omax = max(omax,dp[i]);
    }
    return omax;
}  

int main(){
    maxSumIS();
  return 0;
}
