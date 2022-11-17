// Combinational Sum
// Combination Sum
// https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1#


/*
here in this problem what we have to find that return all the combinations arr from the input array we can form the target sum

run code

see gfg problem

*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void combinationSumUtil(int idx,vector<int>A,int target,vector<int> asf){

    // if target reached to zero then push the curr asf to ans vector
    if(target==0){
        ans.push_back(asf);
        return;
    }

    // if array goes to out of boud or target will be lesser that upcoming elemnet then by addind that arr elment we not get the combinationso return from that case
    if(idx==A.size() || target < A[idx]){
        return;
    }

    // ======================= pick Not pick approch =============================
    // pick the curr elem
    asf.push_back(A[idx]);
    // do not increment idx as it will again added consider case of 2 and 2 again
    combinationSumUtil(idx,A,target-A[idx],asf);
    asf.pop_back();


    // not pick curr elem 
    // else increment idx
    combinationSumUtil(idx+1,A,target,asf);
}
vector<vector<int>> combinationSum(vector<int> A,int target){

    int n=A.size();
    sort(A.begin(),A.end());

    vector<int> temp,asf;

    // removing duplicates
    for(int i=0;i<n-1;i++){
        if(A[i+1]!=A[i]) temp.push_back(A[i]);
    }
    temp.push_back(A[n-1]);

    combinationSumUtil(0,temp,target,asf);

    return ans;

}
           
int main(){
    vector<int> A ={7,2,6,5};
 vector<vector<int>> mat = combinationSum(A,16);

 for(int i=0;i<mat.size();i++){
     for(int j=0;j<mat[i].size();j++){
         cout<<mat[i][j]<<" ";
     }
     cout<<"\n";
 }
  return 0;
}

/*  
    A = {7,2,6,5}  tar = 16
    2 2 2 2 2 2 2 2 
    2 2 2 2 2 6     
    2 2 2 5 5       
    2 2 5 7         
    2 2 6 6         
    2 7 7
    5 5 6
*/ 