// Selection Sort
/*
it also work on virtual partition like sorted part and unsorted part
but like not like insertion sort in these sort size of sorted array is zero initially

algo:
iterate over the array and select min elemets from remaining 
array and place min element from starting that means at position of i 

*/
#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr){
    int n=arr.size();
    // iterate over array element
    for(int i=0;i<n;i++){
        int min=i;
        // find minimum element from un sorted part 
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        // if min and i is diffrent that means another min element is present in array then swap arr(min)  and arr[i]
        if(min!=i){
            swap(arr[min],arr[i]);
        }
    }
}
           
int main(){
    vector<int> arr={1,6,3,4,2};
    selectionSort(arr);
    for(auto i:arr){
        cout<<i<<" ";
    }
  return 0;
}