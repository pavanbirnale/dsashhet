// Count Inversions
// Count Inversions in an array | Set 1 (Using Merge Sort)
#include<bits/stdc++.h>
using namespace std;

long long int inversionCount2(long long arr[], long long N)
{
    int c=0;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(arr[i]>arr[j]) c++;
        }
    }
    return c;
}
long long int merged(long long arr[],long long temp[],long long int lo,long long int mid,long long hi){

    long long int i,j,k,inv_C=0;
    i=lo;
    j=mid;
    k=lo;

    while(i<=mid-1 and j<=hi){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
            inv_C+=mid-i;
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=hi){
        temp[k++]=arr[j++];
    }
    for(int i=lo;i<=hi;i++){
        arr[i]=temp[i];
    }
return inv_C;
}
long long int mergeSort(long long arr[],long long temp[],long long lo,long long hi){
    long long inv_C=0,mid;
    if(lo<hi){
        mid=(lo+hi)/2;
        inv_C+=mergeSort(arr,temp,lo,mid);
        inv_C+=mergeSort(arr,temp,mid+1,hi);
        
        inv_C+=merged(arr,temp,lo,mid,hi);
    }
return inv_C;
}
long long int inversionCount(long long arr[], long long N){
    long long  temp[N];

    return mergeSort(arr,temp,0,N-1);
}
           
int main(){
    long long arr[]={2, 3, 4, 5, 6};

          cout<<inversionCount(arr,5);
  return 0;
}