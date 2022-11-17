// Fina a value in a BST
// Insert a node in a BST
// https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1#
/*
Algo:
to find Node in bst and Insert new Node in Bst
*/
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* Insert(Node* root, int key){
    if(!root){
        Node* temp =new Node{key};
        return temp;
    }
    if(key<root->data){
        root->left=Insert(root->left,key);
    }
    else if(key>root->data){
        root->right=Insert(root->right,key);
    }
    return root;
}

Node* search(Node* root,int key){
    if(!root or root->data==key){
         return root;
    }
    if(key < root->data){
        return search(root->left,key);
    }
    else if(key > root->data){
        return search(root->right,key);
    }
}
int main(){
          
  return 0;
}