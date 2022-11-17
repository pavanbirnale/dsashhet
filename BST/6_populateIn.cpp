// Populate Inorder successor of all nodes
// Given a Binary Tree, write a function to populate next pointer for all nodes. 
// The next pointer for every node should be set to point to inorder successor.
/*
Algo: 
 make a tree like treaded binary tree
 Use prev pointer to reffer previous node
 that currNode node is must be inorder succescor of prev
 so simply connect the prevs next to root
*/
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node* next;
};
void populateNextutil(Node* root,Node* &prev){
    if(!root) return;
    populateNextutil(root->left,prev);
    // here is only logic if prev not Null then connect prevs next to its inorder successor
    if(prev){
        prev->next=root;
    }
    prev=root;
    populateNextutil(root->right,prev);

}
void populateNext(Node* root){
    if(!root) return;
    Node* prev=NULL;
    populateNextutil(root,prev);
    return;
}
           
int main(){
          
  return 0;
}

// left root right
/*
               5
            /     \
           3       7
         /  \    /  \
        2    4  6    8



*/