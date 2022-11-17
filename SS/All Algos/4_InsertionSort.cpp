// Insertion Sort
/*
Insertion sort is simple sorting algorithm it works similar to way we sort playing card in our hand
The array in insertion sort is vertually spit into sorted and unsorted parts.
then pick each value in unsorted part one by one and place it into correct possition in sorted part

Algo:
spilt the array into two part 0 and 1 to N;
pick the element from unsorted part and insert that element to correct possition in sorted part
*/
#include<bits/stdc++.h>
using namespace std;

void InsertionSort(vector<int> &arr){
    int s=arr.size();
    for(int i=1;i<s;i++){
// first loop  move toword ----------------------------> right
        // pick the element here
        int temp=arr[i];
        // set the j to starting point of second loop
        int j=i-1;
        while(j>=0 and arr[j]>temp){
// right <---------------------------------second loop move toward right
            arr[j+1]=arr[j];
            j--;
        }
        // here j+1 because jis decremeted in above line
        arr[j+1]=temp;
    }
}

int main(){
    vector<int> arr={1,6,3,4,2};
    InsertionSort(arr);
    for(auto i:arr){
        cout<<i<<" ";
    }
  return 0;
}