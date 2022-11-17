// Find LCA in a Binary tree;
// Lowest Common Ancestor in a Binary Tree 
// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1


/*

    1
   /  \
  2    3

  for these example n1=2 and n2=3

  try to do dray run it is very easy
*/
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right; 
};
Node* LCA(Node* root ,int n1,int n2){

    if(!root) return NULL;
    // due to unique n1 and n2 values in recurtion is data mached then return from it 
    if(root->data==n1 or root->data==n2) return root;

// pass recurtion to left and right and try to get l and r node if both l and r of any node are find then the root becomaes lca 
    Node* l=LCA(root->left,n1,n2);
    Node* r=LCA(root->right,n1,n2);

// if both are find then these block exicuted;
    if(l and r) return root;
    if(l) return l;
    else return r;
}

int main(){
          
  return 0;
}

