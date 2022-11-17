// find the minimum distance between two nodes of binary Tree
// Find distance between 2 nodes in a Binary tree
// https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1#
/*
Algo:
First of all min distance between two node is the sum of their individual distance from their LCA
so first we find LCA of that node and then in another function we get distance of that noce from root
*/
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};
// these is function for finding LCA of that two nodes
Node* LCA(Node* root,int n1,int n2){
    if(!root) return NULL;
    if(root->data==n1 or root->data==n2) return root;

    Node* l=LCA(root->left,n1,n2);
    Node* r=LCA(root->right,n1,n2);
    if(l and r) return root;
    if(l) return l;
    else return r;
}

// this is another utility function for calulatin number of edges of height from bottom to root node by return ning 1;
int findDist(Node* root, int d){
    if(!root) return 0;
    if(root->data==d) return 1;

    int a=findDist(root->left,d);
    int b=findDist(root->right,d);

    if(!a and !b) return 0;
    else return a+b+1;
}

int MinDist(Node* root, int a, int b){
   if(!root) return NULL;

   Node* lca=LCA(root,a,b);

   int h1 =findDist(lca,a); 
   int h2 =findDist(lca,b);
//    -2 for subtracting two additional counts
   return h1+h2-2; 
}
int main(){
          
  return 0;
}