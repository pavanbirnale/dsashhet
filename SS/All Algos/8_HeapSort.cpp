#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr,int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<n and arr[l]>arr[largest]){
        largest=l;
    }
    if(r<n and arr[r]>arr[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void heapSort(vector<int> &arr,int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
           
int main(){
    vector<int> arr={1,5,3,4,2};
    int n=arr.size();
    heapSort(arr,n);
    for(auto i:arr){
        cout<<i<<" ";
    } 
  return 0;
}