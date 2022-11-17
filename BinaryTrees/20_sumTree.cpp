#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

    int solve(Node* root){
        if(!root) return 0;
        int a=solve(root->left);
        int b=solve(root->right);
        int x=root->data;
        root->data=a+b;
        return x+a+b;
    }
    void toSumTree(Node *node)
    {
        solve(node);
    }
int main(){
          
  return 0;
}