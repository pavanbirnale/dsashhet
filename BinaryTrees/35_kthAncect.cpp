// To find kth ancesctor of binary tree
// Kth ancestor of a node in binary tree
// Kth Ancestor of node in a Binary tree
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// these is main function to find kth acestor
Node* temp;
Node* KthAcestor(Node* root , int d,int &k){
    if(!root) return NULL;
    // if these conditon gets true then check for acestor and is reaches to zero then 
    // store the curr node into temp and finaly return data of temp
    if(root->data==d || KthAcestor(root->left,d,k) ||KthAcestor(root->right,d,k)){
        if(k>0) k--;
        else if(k==0){
            temp=root;
            return NULL;
        }
      return root;
    }
    return NULL;
}
           
int main(){
 Node *root=newNode(1);
    root->left=newNode(-2);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right=newNode(3);
    root->right->left=newNode(-6);
    root->right->right=newNode(2);
 
    int k = 3;
    int node = 5;
 
    // print kth ancestor of given node
    Node* parent = KthAcestor(root,node,k);
    if(!temp) cout<<-1;
    else cout<<temp->data;
  return 0;
}