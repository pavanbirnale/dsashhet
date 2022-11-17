// maximum product subarray
// Product array puzzle 
// like kadanes algo but not exactly
// these problems 2nd efficient approch not handle all the corner cases like {0,0,0,0,24,0} like problem
// officialy mention in gfg

// so we use code libraries approch

/*
Algo:
like prefix sum calculate prefix product and post fix product

for array {10, 3, 5, 6, 2} we need 
left : {1, 10 ,30 ,150, 900}
right: {1, 2 ,12 ,60,180}

after reverse 
right : {180 ,60, 12, 2 ,1}

final output: {180 ,600,360,300,900}
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> MaxProduct(vector<int> arr,int n){
    vector<int> left,right,output;
    left.push_back(1);
    right.push_back(1);
    for(int i=0;i<n;i++){
        left.push_back(left[i]*arr[i]);
    }
    for(int i=n-1;i>0;i--){
        right.push_back(right[n-1-i]*arr[i]);
    }
    reverse(right.begin(),right.end());
     for(int i=0;i<n;i++){
        //  cout<<left[i]*right[i]<<" ";
        output.push_back(left[i]*right[i]);
    }
    return output;
}

int main(){
          vector<int> arr={10, 3, 5, 6, 2};
          vector<int> arr2=MaxProduct(arr,5);
          for(auto itr : arr2){
              cout<<itr<<" ";
          }
  return 0;
}