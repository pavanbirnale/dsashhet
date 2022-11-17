#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    struct TreeNode* right;
    struct TreeNode* left;
    TreeNode(int x){
        data=x;
        right = left = NULL;
    }
};

vector<int> LevelOrder(TreeNode* root){
    vector<int> ans;
    if(!root) return ans;
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode* t=q.front();
        q.pop();
        if(t==NULL){
            if(q.size()>0) q.push(NULL);
        }
        else{
            ans.push_back(t->data);
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
    }
    return ans;
}
           
int main(){
          
  return 0;
}