// Treaded Binary Tree postorder traversal
// Applications
// Morris Traversal In Binary Tree 
/*
The idea of threaded binary trees is to make postorder traversal faster and do it without stack and without recursion. A binary tree is made threaded by making all right child pointers that would normally be NULL point to the postorder successor of the node (if it exists). ... The dotted lines represent threads
*/

/*
Algo:
alll same like postorder the only differnce is that prind the data when tread is created 
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
    while(leftNode->left !=NULL and leftNode->left !=root){
        leftNode=leftNode->left;
    }
return leftNode;
}
vector<int> TreadedBinaryTree(Node* root){
    if(!root) return {};
    vector<int> ans;
    while(root){
        Node* leftNode=root->right;
        if(!leftNode){
            ans.push_back(root->data);
            root=root->left;
        }
        else{
            Node* rightMost=getRightMostNode(leftNode,root);
            if(rightMost->left==NULL){
                rightMost->left=root;
                ans.push_back(root->data);
                root=root->right;
            }
            else{
                root=root->left;
                rightMost->left=NULL;
            }
        }
    }
    return ans;
}
void postorder(Node* root){
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
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
    postorder(root);
  return 0;
}