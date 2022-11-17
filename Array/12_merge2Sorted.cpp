// Merge Without Extra Space 
// merge two sorted array without using extra space
// Hard

// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1

/*
Algo:
see the gfg ide for more tle approches

here we use three pointer approch 
so what we have to do is return two arrays theay are give coninues sorted list when place one after other

so for that iniitialize 
i to zeroth position of arr1
k to last possition of arr1
j to start position of arr2 

use for loop and check if arr1 i th element is less than arr2s jth elem then the arr[i] is in its correct possion
so move i to i++;
if these condition goes to false then in else part
such jth elem present in arr2 whose position must be in arr1
so swap the arr1[k] with arr2[j] and increment j and decrement k;

these is beacuse we have given sorted array


at last sort the array 
we not have to return
*/

#include<bits/stdc++.h>
using namespace std;

void mergeSortedArray(int arr1[],int arr2[],int n,int m){
    int i = 0;
    int k = n-1;
    int j=0;

    while(i <= k && j < m ){
        if(arr1[i]<arr2[j]){
            i++;
        }
        else{
            swap(arr2[j],arr1[k]);
            j++;
            k--;
        }
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
}

int main(){
    int arr1[]={1, 3, 5, 7};
    int arr2[]={0, 2, 6, 8, 9};
    int n= sizeof(arr1)/sizeof(arr1[0]);
    int m= sizeof(arr2)/sizeof(arr2[0]);
    mergeSortedArray(arr1,arr2,n,m);
    for(int i=0;i<n;i++){
        cout<<arr1[i]<<" ";
    }
    for(int i=0;i<m;i++){
        cout<<arr2[i]<<" ";
    }
  return 0;
}