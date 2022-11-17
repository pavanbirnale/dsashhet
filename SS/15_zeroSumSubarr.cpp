// print all subarrays with 0 sum
// Zero Sum Subarrays
// Approch from pepcoding video

// approch is very simple store tyhe frequence of sum in a map
//  as the sum comes again that mence such a subarry present in it that decrese the sum to zero
//  add the freq to count
// main point iniitialy set freq of 0 to one
#include<bits/stdc++.h>
using namespace std;

int FindZeroSum(int arr[],int n){

    int count=0;
    unordered_map<int,int> mp;
    mp[0]=1;
    int i=0;
    int sum=0;
    while(i<n){
        sum+=arr[i];
        if(mp.find(sum)!=mp.end()){
            count+=mp[sum];
            mp[sum]=mp[sum]+1;
        }
        else{
            mp[sum]++;
        }
        i++;
    }
    return count;
}
           
int main(){
          int arr[]={0,0,5,5,0,0};
          cout<<FindZeroSum(arr,6);
  return 0;
}