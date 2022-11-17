// Check if a Binary Tree is Heap
// Is Binary Tree Heap

/*
Algo :  we know that heap has two properties:
1.it is a complte binary tree
2.for evry node data at chld node must be less that parent node => for max heap

so we check these properties 

1. find numbers of node in tree
2. then for evry node if is idx is>=n then it not be heap

as in array format for any node is left child is present at 2*i+1 pos and right 2*i+2 pos

*/
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
// calculate number of nodes in tree
int size(Node* root){
    if(!root) return 0;
    return 1+size(root->left)+size(root->right);
}
bool checkheap(Node* root,int i,int n){
    if(!root) return 1;

// condition for comlpete bst think like arr heap
    if(i>=n) return 0;

// condition for heap condition
    if(root->left && root->left->data >= root->data || root->right && root->right->data >= root->data){
        return 0;
    }
    return checkheap(root->left,2*i+1,n) && checkheap(root->right,2*i+2,n);
}
bool isheap(Node* root){
    if(!root) return 1;

    int idx=0;
    int n=size(root);

    if(checkheap(root,idx,n)){
        return 1;
    }
    return 0;
}
           
int main(){
          
  return 0;
}