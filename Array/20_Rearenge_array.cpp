// Rearrange the array in alternating positive and negative items with O(1) extra space
// https://youtu.be/zUPMACE0uBs

// algo
// 1.rearege +ve to one side and -ve to other side
// 2.After that i reach to such index that is first negative element 
// 3.and use k var and swap arr[k] and arr[i] and incress i by one step and k by two steps  
#include<bits/stdc++.h>
using namespace std;

vector<int> rearange(vector<int> arr){
int s=arr.size();

int i=0,j=s-1;

while(i<j){
    while(i<=s and arr[i]>0){
        i++;
    }
    while(j>=0 and arr[j]<0){
        j--;
    }
    if(i<j)
    swap(arr[i],arr[j]);
}
if(i==0 || i==s) return arr;

// -6 10 -8 5 -2 9 -3 1 
// 1 10 9 5 -6 -8 -2 -3 

int k=0;
while(k<i){
    swap(arr[k],arr[i]);
    i=i+1;
    k=k+2;
}
return arr;
}

int main(){
    vector<int> arr={1,-3,-2,5,-6,-8,9,10};
    vector<int> ans=rearange(arr);
    for(int i=0;i<8;i++){
    cout<<ans[i]<<" ";
}
    return 0;
}
