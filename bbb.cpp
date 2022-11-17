
#include<bits/stdc++.h>
using namespace std;
           
int LIS(vector<int> arr,int n){
     vector<int> dp(n);
     int omax=0;
     for(int i=0;i<n;i++){
         int ma=0;
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
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
      cout<<LIS(arr,n);
  return 0;
}
