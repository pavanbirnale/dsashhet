// Find min and max value in a BST
// Minimum element in BST
/*
ALgo: Two approches:
 1st : O(N) visit each and every node and compare curr num with min as follow
 2nd : O(h) below approch

 see in dsa/bst also
*/
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

int MinElem(Node* root){
    if(!root) return -1;
    else if(root->left==NULL){
        return root->data;
    }
    else{
        return MinElem(root->left);
    }
}

int MaxElem(Node* root){
    if(!root) return -1;
    else if(root->right==NULL){
        return root->data;
    }
    else{
        return MaxElem(root->right);
    }
}
           
int main(){
          
  return 0;
}