// Notes written in Revision of 22/01/2022
//  Merge sort 
// See merge two sorted array without extra space ( not necessary)

/*

// rest of all the sorting algos that u learn are in place sorting algos but merge sort is not in place sorting algo
// so what is mens by in place => 
An in-place algorithm is an algorithm that does not need an extra space and produces an output in the same memory that contains the data by transforming the input ‘in-place’. However, a small constant extra space used for variables is allowed.

ref : https://www.geeksforgeeks.org/in-place-algorithm/
*/

/*
Algo : 
What we do is we have two functions : 
1). mergeSort => fuction that divied the array into subarrays until array has single element 
2).merge      => function that use to merge the arrays
merge function is very simple in that only comapre the ith and jth element of array A and push smaller element out of which to array B
until i should less than eql to mid and j< hi
and at last if any array is remain then push them to B
and dont forget to update array to B
*/
#include<bits/stdc++.h>
using namespace std;

void Merge(vector<int> &arr,int lo,int mid,int hi){
// set i,j,k to lo,mid+1 and k to 0
int i=lo;
int j=mid+1;
int k=0;
// n size of array B
int n=(hi-lo)+1;
int b[n];
// use while loop until i<= mid and j<=hi
while(i<=mid && j<=hi){
    if(arr[i]<arr[j]){
        b[k]=arr[i];
        i++;
        k++;
    }
    else{
        b[k]=arr[j];
        j++;
        k++;
    }
}
while(i<=mid){
      b[k]=arr[i];
        i++;
        k++;
}
while(j<=hi){
      b[k]=arr[j];
        j++;
        k++;
}
for(int itr : b){
    // important only add from lo 
    arr[lo]=itr;
    lo++;
}
}

// main merge sort function
void MergeSort(vector<int> &arr,int lo,int hi){
    // divide the array into subarrays util array has single element by half -half
    if(lo<hi){
        int mid=(lo+hi)/2;
        MergeSort(arr,lo,mid);
        MergeSort(arr,mid+1,hi);
        Merge(arr,lo,mid,hi);
    }
}
           
int main(){
    vector<int> arr={1,5,3,4,2};
    int n=arr.size();
    MergeSort(arr,0,n);
    for(auto i:arr){
        cout<<i<<" ";
    }
  return 0;
}