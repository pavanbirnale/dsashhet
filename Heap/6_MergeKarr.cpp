// Merge “K” sorted arrays. [ IMP ]
// Merge k Sorted Arrays 
// heap
/*
Algo : by using heap;

 TC : K^2*log K
 SC : O(K)
*/
#include<bits/stdc++.h>
using namespace std;


vector<int> mergeArr(vector<vector<int>> arr,int k){

    vector<int> ans;
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;

    // push first k element to pq
    for(int i=0;i<k;i++){
        vector<int> curr={arr[i][0],i,0};
        pq.push(curr);
    }
    
    // then pop one by one elemnt and simultenously add element
    while(!pq.empty()){
        vector<int> curr = pq.top();
        pq.pop();
        ans.push_back(curr[0]);

        // curr arr possition and value possition 
        int ap=curr[1];
        int vp=curr[2];

// due to same size of all array these technique works
        if(vp+1<k){
            vector<int> curr2={arr[ap][vp+1],ap,vp+1};
            pq.push(curr2);
        }
    }
    return ans;

}
           
int main(){
    vector<vector<int>> arr={{1,2,3,4},{2,2,3,4},{5,5,6,6},{7,8,9,9}};
    vector<int> ans=mergeArr(arr,4);
    for(int itr : ans){
        cout<<itr<<" ";
    }
  return 0;
}