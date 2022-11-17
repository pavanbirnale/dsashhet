// Treaded Binary Tree preorder traversal
// Applications
// Morris Traversal In Binary Tree 
/*
The idea of threaded binary trees is to make preorder traversal faster and do it without stack and without recursion. A binary tree is made threaded by making all right child pointers that would normally be NULL point to the preorder successor of the node (if it exists). ... The dotted lines represent threads
*/

/*
Algo:
alll same like preorder the only differnce is that prind the data when tread is created 
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int d){
   Node * temp=new Node();
   temp->left=NULL;
   temp->right=NULL;
   temp->data=d;
   return temp; 
}
Node* getRightMostNode(Node* leftNode,Node* root){
    while(leftNode->right !=NULL and leftNode->right !=root){
        leftNode=leftNode->right;
    }
return leftNode;
}
vector<int> TreadedBinaryTree(Node* root){
    if(!root) return {};
    vector<int> ans;
    while(root){
        Node* leftNode=root->left;
        if(!leftNode){
            ans.push_back(root->data);
            root=root->right;
        }
        else{
            Node* rightMost=getRightMostNode(leftNode,root);
            if(rightMost->right==NULL){
                rightMost->right=root;
                ans.push_back(root->data);
                root=root->left;
            }
            else{
                rightMost->right=NULL;
                root=root->right;
            }
        }
    }
    return ans;
}
void preorder(Node* root){
    if(!root) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
           
int main(){
    Node *root=newNode(1);
    root->left=newNode(-2);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right=newNode(3);
    root->right->left=newNode(-6);
    root->right->right=newNode(2);
    vector<int> ans=TreadedBinaryTree(root);
    for(auto i:ans) cout<<i<<" ";
    cout<<"\n";
    preorder(root);
  return 0;
}