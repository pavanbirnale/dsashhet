// Maximum subsequence sum such that no three are consecutive

// THis problem is extention of  Stickler Thief : D:\dataStructure\DSASheet\SS\12_SticklerThief.cpp
// House Robber - 1 leetcode

 /*
 What ? : Given a sequence of positive integer find the maximum sum that can be form which has no consecutive elements present
 */

//  REad the article :  https://www.geeksforgeeks.org/maximum-subsequence-sum-such-that-no-three-are-consecutive/
 
#include<bits/stdc++.h>
using namespace std;
           
int maxSeqSum(int arr[],int n){
    int sum[n];
    //  here > symbol is because if n>1 then store the result if we use -- then that not store the result so use >
    if(n >= 1 ){
        sum[0] = arr[0];
    }
    if(n >= 2){
        sum[1] = sum[0] + arr[1]; 
    }
    if(n > 2){
        // exclude one by one
        sum[2] = max({arr[0] + arr[1], arr[0] + arr[2] , arr[1] + arr[2]})
    }

     
    // Process rest of the elements
    // We have three cases
    // 1) Exclude arr[i], i.e., sum[i] = sum[i-1]
    // 2) Exclude arr[i-1], i.e., sum[i] = sum[i-2] + arr[i]
    // 3) Exclude arr[i-2], i.e., sum[i-3] + arr[i] + arr[i-1]

    for(int i=3;i<n;i++){
        sum[i] = max({sum[i-1],sum[i-2] + arr[i],sum[i-3] + arr[i] + arr[i-1]});
    }
    return sum[n-1];
}
           
int main(){
      f();
  return 0;
}

