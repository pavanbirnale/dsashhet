// Count triplet with sum smaller than a given value
// Count triplets with sum smaller than X
/*
Algo:
Approch 1: Use three loop and for each and every element check condition
first loop from 0 to n-2
second loop from i+1 to n-1
third loop from j+1 to n
https://www.geeksforgeeks.org/count-triplets-with-sum-smaller-that-a-given-value/


Approch 2:
1. sort the array 
2. then for every i check for j to k utill j<k that mens they not overcome each other
set j to i+1
and set k to last element

in while loop is sum is greater than sum variable then decriment k

else there are k-j terms can gives sum smaller than sum varable so add them to ans

and increment j++;
*/
#include<bits/stdc++.h>
using namespace std;

int countTriplets(int arr[],int n,int sum){
    sort(arr,arr+n);
    int ans=0;
    for(int i=0;i<n-2;i++){
        int j=i+1;
        int k=n-1;

        while(j<k){
            if(arr[i]+arr[j]+arr[k]>=sum){
                k--;
            }
            else{
                ans+=(k-j);
                j++;
            }
        }
    }
    return ans;
}
           
int main(){
    int arr[]={5, 1, 3, 4, 7};
    cout<<countTriplets(arr,5,12);
  return 0;
}