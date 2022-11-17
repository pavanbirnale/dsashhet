// K-th Largest Sum Contiguous Subarray
// K-th max Sum Contiguous Subarray

// here we used prefixed sum 
// and stored that sum to sum array
// then iterate over the sum and and push curr sum to pq and reterun pq.top at last
// as in problem largest is used then we have to use min heap
#include<bits/stdc++.h>
using namespace std;

int KthMaxSum(int arr[],int n,int k){

    int sum[n+1];
    priority_queue<int,vector<int>,greater<int>>pq;
    sum[0]=0;
    sum[1]=arr[0];
    for(int i=2;i<=n;i++){
        sum[i]=sum[i-1]+arr[i-1];
    }

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int currSum=sum[j]-sum[i-1];
            if(pq.size()<k){
                pq.push(currSum);
            }
            else{
                // if top is lesser that curr sum then pop top and push curr sum to pq
                if(pq.top()<currSum){
                    pq.pop();
                    pq.push(currSum);
                }
            }
        }
    }

    return pq.top();
}
           
int main(){
    int arr[]={20, -5, -1};

    cout<<KthMaxSum(arr,3,3);
  return 0;
}