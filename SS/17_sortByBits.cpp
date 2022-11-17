// Sort by Set Bit Count
// Sort array according to count of set bits
// for counting number of set bits in any number cpp __builtin_popcount(a) function is used

// kernighans algorithm is used to find right most set bit of any number (num & -num) approch

#include<bits/stdc++.h>
using namespace std;

static bool comp(int a,int b){
    // these method isuse to count set bits in int
    return __builtin_popcount(a)>__builtin_popcount(b);
}
void sortArr(int arr[],int n){

// stable sort is important for arranginag array arroding to original arry if set bits are same
    stable_sort(arr,arr+n,comp);
}
int main(){
    int arr[]={5, 2, 3, 9, 4, 6, 7, 15, 32};
    int n=sizeof(arr)/sizeof(arr[0]);
    sortArr(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
  return 0;
}