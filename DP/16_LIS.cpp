// Longest Incressing Subsequence || LIS || Longest Increasing Subsequence


/*
This problems are come in singal group : 

Group 5 : Longest Incressing subsequence (LIS)
1. Longest Incresing Subsequence
2. Maximum Sum Incresing Subsequence
3. Longest Bitonic Subsequences
4. Maximum non Overlaping bridges
5. Russian Doll Problem

*/


/*
Here in this problem we have to find the count of longest increasing subsequence of array
So, First of all we the diffence between subsequence , subsets ,subarray and substring
so subsequence == subsets there are 2^n subsequence or subsets for every n size element
and substring == subarray  there are n(n-1) substrings or subarray for every n size element

more specifically subset and subarray are teminologies for array
and subsequence and substring are for string

*/
/*
Algorithm : 
1. What ? : we create 1D dp and smallest problem is at start so we start solving from start 
each dp cell store that what is the maximum LIS we can from that end with curr arr element 

Image : https://res.cloudinary.com/darshanscloud/image/upload/v1644567853/htc96iir6nfjqcqsypeg.png

In image in each column we store the subsets that are froms such that ends with curr arr elem


2.How ? : use two for loop in inner loop comare all the elemnets that are less than curr elem and take max of them and add +1 to max 
that will be the count of LIS fromed such that last element is curr elem
*/

 
 
#include<bits/stdc++.h>
using namespace std;
           
int LIS(vector<int> arr,int n){
     vector<int> dp(n);
     int omax=0;
     for(int i=0;i<n;i++){
         int ma=0;
        //  find the maximum count such that curr char is greter than all prev
         for(int j=0;j<i;j++){
             if(arr[j]<arr[i]){
                 ma=max(ma,dp[j]);
             }
         }
         dp[i] =ma+1;
         omax=max(omax,dp[i]);
     }
     return omax;
}
           
int main(){
    vector<int> arr ={0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
      cout<<LIS(arr,16);
  return 0;
}
