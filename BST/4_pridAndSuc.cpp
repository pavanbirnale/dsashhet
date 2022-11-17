// Predecessor and Successor
// Find inorder successor and inorder predecessor in a BST
/*
Algo : 
1.For Inorder Sucessor: first go to one step right and then goto extreame left
2.For Inorder predicessor : first to one step to left and then go to extreame right
*/


#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

// this are utility functions for finding predisesor and sucessor of node ratharer than leaf Node
Node* inPred(Node* root){
    Node* p=root->left;
    while(p->right) p=p->right;
    return p;
}
Node* inSuc(Node* root){
    Node* p=root->right;
    while(p->left) p=p->left;
    return p;
}

// function that find inoder predicessor and successor
void FindPredAndSuc(Node* root, Node* &pred, Node* &suc,int key ){

// base case
if(!root) return;

// 1st case if data matches to key 
if(root->data==key){
    if(root->left) pred=inPred(root);
    if(root->right) suc=inSuc(root);
    return;
}

// if key is gretter than data then move toward right subtree and kkep track of predcesor
if(root->data<key){
    pred=root;
    FindPredAndSuc(root->right,pred,suc,key);
}
// if key is less than data them move to right subtree and keep trak of sucessor
else if(root->data>key){
    suc=root;
    FindPredAndSuc(root->left,pred,suc,key);
}
}
int main(){
          
  return 0;
}