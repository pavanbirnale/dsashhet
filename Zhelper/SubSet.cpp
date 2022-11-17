// Generate all the subset of given array

// TC : O(2^n);
// SC : O(n*2^n);

// There are 2^n subsets of n size array/set

/* There are Two Approches to find the subsets of set
   1). BackTracking (Recursive)
   2). Power Set (Iterative)  : Powerset of set/arr A is set of all subset of A
*/

#include<bits/stdc++.h>
using namespace std;

// 1).BackTracking : 

void Subsets(vector<int> arr,int i,vector<vector<int>>& ans ,vector<int>& curr){
    ans.push_back(curr);
    for(int j=i;j<arr.size();j++){
        curr.push_back(arr[j]);
        Subsets(arr,j+1,ans,curr);
        curr.pop_back();
    }
}










// 2).Power set : https://www.geeksforgeeks.org/power-set/
// short form : pss => power set size

vector<vector<int>> PowerSet(vector<int> arr){
    int n = arr.size();
    vector<vector<int>> ans;
    unsigned int pss = pow(2,n);
    int c, j;
    for(c = 0; c < pss; c++){
        vector<int> temp = {};
        for(j = 0; j < n; j++){
            if(c & (1 << j))
                temp.push_back(arr[j]);
        }
        ans.push_back(temp);
    }
    sort(ans.begin(),ans.end());
    return ans;
}
           











int main(){
    // BackTracking :
    vector<int> arr = {1,2,3};
    vector<vector<int>> ans;
    vector<int> curr;
    Subsets(arr,0,ans,curr);


    // power set :
    vector<vector<int>> ans2 = PowerSet(arr);
    for(auto row : ans2){
        for(auto i : row){
            cout<<i<<" ";
        }
        cout<<endl;
    }
  return 0;
}
