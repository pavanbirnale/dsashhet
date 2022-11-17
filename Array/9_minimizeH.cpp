// Minimize the Heights II 
// https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1#

/*
this problem is solved in rivition of 11/1/22
Algo:
what we have to do is minimize the heights diff

so the intitive approch is that we can minimize diff when we add k to smalllest number and subtract k from largest number
repitive in for loop
*/

#include<bits/stdc++.h>
using namespace std;

int getMinHeights(int arr[],int n,int k){
    sort(arr,arrr+n);

    int Max = arr[n-1];
    int Min = arr[0];

    int diff = Max-Min;

    for(int i=1;i< n;i++){
        if(arr[i]<0) continue;

        Min=min(arr[0]+k,arr[i]-k);
        Max=max(arr[n-1]-k,arr[i-1]+k);

        diff=min(diff,Max-Min);

    }
    return diff;
}
           
int main(){
          
  return 0;
}