// Longest Bitonic subsequence



/*
This problems are come in singal group : 

Group 5 : Longest Incressing subsequence (LIS)
1. Longest Incresing Subsequence
2. Maximum Sum Incresing Subsequence
3. Longest Bitonic Subsequences
4. Maximum non Overlaping bridges
5. Russian Doll Problem
6. Perfect Squares
*/



// basically Bitonic sequence is combination of LIS and LDS

//  here what we do is in dp1 store the LIS

//  and in dp2 store LDS
// for nothing to do is only traverse arr from back only and store results

 
 
#include<bits/stdc++.h>
using namespace std;
           
int LongestBitonicSequence(vector<int>nums)
	{
	  int n=nums.size();
	  
	  vector<int> dp1(n),dp2(n);
	  
    // 	  for LIS
	  for(int i=0;i<n;i++){
	      int ma = 0;
	      for(int j=0;j<i;j++){
	          if(nums[j]<nums[i] && dp1[j]>ma){
	              ma=dp1[j];
	          }
	      }
	      dp1[i]= ma+1;
	  }
	  
   // 	  for LDS
     for(int i=n-1;i>=0;i--){
         int ma=0;
         for(int j=n-1;j>i;j--){
             if(nums[j]<nums[i] && dp2[j]>ma){
                 ma=dp2[j];
             }
         }
         dp2[i] = ma+1;
     }
     int ans = 0;
     for(int i=0;i<n;i++){
         ans = max(ans,dp1[i]+dp2[i]-1);
     }
     return ans;
	}
           
int main(){
      f();
  return 0;
}