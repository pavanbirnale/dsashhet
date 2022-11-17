// Treaded Binary Tree inorder traversal
// Applications
// Morris Traversal In Binary Tree 
/*
The idea of threaded binary trees is to make inorder traversal faster and do it without stack and without recursion. A binary tree is made threaded by making all right child pointers that would normally be NULL point to the inorder successor of the node (if it exists). ... The dotted lines represent threads
*/

/*
Algo:

Treded Binary Tree is special kind of binary tree in which treads are present treads are made by every right child that is NULL by pointing to Inoder successor is it is exist

Two type of Treted Bianry trees
1.Single Treaded Binary Tree : made by only pointing to right Null child to inorder successor
2.Dubble Treaded Binary Tree : Both the NULL left and right pointes to inoder sucessor and predicesor

Intution:
first of all traverse the while loop untill root become null
 here we point rightmost node to find inorder sucessor of that node so we follow preocess of inorder sucessor
 after geting that inorder suceesor ifits right is null that mense the tread is not present so create a treads that meanse 
 attached the rightmost->right to root and move root to left size

 here we only push the data to vector iff when left node become empty or white tread breaking thse is important
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
                root=root->left;
            }
            else{
                rightMost->right=NULL;
                ans.push_back(root->data);
                root=root->right;
            }
        }
    }
    return ans;
}
void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
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
    inorder(root);
  return 0;
}