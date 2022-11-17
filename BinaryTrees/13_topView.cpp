// Top View of a tree;
/*
Algo: TC : O(N) , SC : O(N)
It is also level order lke approch 
here we use verticle level order approch
first of all we push node and its line to que the for each line that
 means for each quew.second is it is present in map or not that means 
 we only push ist elemnt of line in map with line as index

//  here we use map and not unorderd map beacause map store sorted elments
*/
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int data;
    struct TreeNode* right;
    struct TreeNode* left;
};

vector<int> TopView(TreeNode* root){
    vector<int> ans;
    if(!root) return ans;
    queue<pair<TreeNode*,int>> q;
    map<int,int> map;
    q.push({root,0});
    while(!q.empty()){
        auto itr=q.front();
        q.pop();
        TreeNode* t=itr.first;
        int line=itr.second;
        
        if(map.find(line)==map.end()) map[line]=t->data;

        if(t->left)  q.push({t->left,line-1});
        if(t->right) q.push({t->right,line+1});
    }
    for(auto itr:map){
        ans.push_back(itr.second);
    }
}
int main(){
          
  return 0;
}