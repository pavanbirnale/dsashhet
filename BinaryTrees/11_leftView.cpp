#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    struct TreeNode* right;
    struct TreeNode* left;
};

vector<int> LeftView(TreeNode * root){
    vector<int> ans;
    if(!root) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int sz=q.size();
        ans.push_back(q.front()->data);
        while(sz--){
            TreeNode* t=q.front();
            q.pop();
            if(t->left)q.push(t->left);
            if(t->right)q.push(t->right);
        }
    }
    return ans;
}
           
int main(){
          
  return 0;
}