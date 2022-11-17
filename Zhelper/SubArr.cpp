// Code to Generate All Subarrays of Array

// TC : O(n^3);
// SC : O(1);
// there are n*(n+1)/2 non-empty subarrays for n length arr.
 
 
#include<bits/stdc++.h>
using namespace std;
           
vector<vector<int>> GenerateSubArr(vector<int> arr){
     int n = arr.size();
     vector<vector<int>> ans;
     for(int i=0;i<n;i++){
         for(int j=i;j<n;j++){
             vector<int> temp = {};
             for(int k=i;k<=j;k++){
                 temp.push_back(arr[k]);
             }
             ans.push_back(temp);
         }
     }
     return ans;
}
           
int main(){
    vector<int> arr = {1, 2, 3, 4};
      vector<vector<int>> ans = GenerateSubArr(arr);
      for(auto row : ans){
          for(auto i : row){
              cout<<i<<" ";
          }
          cout<<endl;
      }
  return 0;
}