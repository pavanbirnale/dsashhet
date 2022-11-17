// Check for BST 
// Check if a tree is a BST or not 
// inoder liked approch
/*
Algo:
Two Approches : 

TC: O(n) SC: O(n) where n is number of nodes
    1.first find array of inorder traversal and check if it is sorted or not then return that

TC: O(n) SC: O(1)
    2.Use prev pointer to refer previous Node
    And do inorder like algo
*/
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
}; 

void solve(Node* root, Node* &prev,int&f){
        if(!root) return;
        solve(root->left,prev,f);
        if(prev and root->data<= prev->data){
            f=0;
            return;
        }
        prev=root;
        solve(root->right,prev,f);
    }
    bool isBST(Node* root) 
    {
        int f=1;
        Node* prev=NULL;
        solve(root,prev,f);
        return f;
    }

int main(){
          
  return 0;
}