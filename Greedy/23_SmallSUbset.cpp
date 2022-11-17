// Smallest subset with sum greater than remaining  other elements
// https://www.youtube.com/watch?v=YrdVt9TC6gA&list=PLDdcY4olLQk3cAxZPJXMbxqrM3PlNkmO8&index=13
// simple  problem

#include<bits/stdc++.h>
using namespace std;

int SmallestSubsetSum(int arr[],int n){

    int totalSum=0;
    int subsetSum=0;
    // sort the array
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        totalSum+=arr[i];
    }
    int count=0;
    int j=n-1;
    while(1){
        subsetSum+=arr[j];
        totalSum-=arr[j];
        j--;
        count++;
        if(subsetSum>totalSum){
            break;
        }
    }
    return count;
}

int main(){
    int arr[]={1,1,3,7};
    cout<<SmallestSubsetSum(arr,4);
}