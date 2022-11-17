// Notes written in revision of day 22/1/2022
// Jenny Lect :  https://www.youtube.com/watch?v=QN9hnmAgmOc&list=PLdo5W4Nhv31bbKJzrsKfMpo_grxuLl8LU&index=100

// Quick Sort || Partition sorting algorithm || Divied and conquer algorithm
/*

*/
#include<bits/stdc++.h>
using namespace std;

// partition function used to place pivot number to its correct possition and 
// place numbers less that pivot of left side and greater to right side of pivot
/*
There are three methods to set pivot we set it to !st index
*/
int partition(vector<int> &arr,int lo,int hi){
    int pivot=arr[lo];
    int start=lo;
    int end=hi;

// incress and decrees  start and end util they overcome each other
    while(start<end){
        // if arr[start] is less than or equal pivot then incress start++
        // means in simple words if element is smaller than pivot then it must be to left side so incress start
        while(arr[start]<=pivot){
            start++;
        }
        // if arr[end] is more than pivot thn decrees end
        // means if number is greter than pivot then it should have be to right side so decrees end
        while(arr[end]>pivot){
            end--;
        }

        // and when start is less than end then swap arr[start] and arr[end]
        if(start<end){
            swap(arr[start],arr[end]);
        }
    }
    // at last swap lo and end
    swap(arr[lo],arr[end]);
    // return end  then element at index end is at its correct position and in next call pass end-1 & end+1 to recursive function
    return end;
}


// this is quick sort function
void QuickSort(vector<int> &arr,int lo,int hi){
// which runs until lo is less than hi and pass the partition to recursive function
if(lo<hi){
    int loc=partition(arr,lo,hi);
    QuickSort(arr,lo,loc-1);
    QuickSort(arr,loc+1,hi);
}
else return;
}
           
int main(){
    vector<int> arr={1,6,3,4,2};
    int n=arr.size();
    QuickSort(arr,0,n);
    for(auto i:arr){
        cout<<i<<" ";
    }
  return 0;
}