// same approch like top view but in this one line of code is changed that is of line 22 
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int data;
    struct TreeNode* right;
    struct TreeNode* left;
};

vector<int> BottomView(TreeNode* root){
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
        
        map[line]=t->data;

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