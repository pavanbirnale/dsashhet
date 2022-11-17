// maximum SubTree Sum
// Find Largest subtree sum in a tree
// https://www.geeksforgeeks.org/find-largest-subtree-sum-tree/
// Only article
//  complete tree contructed here that means full problen can run
/*
here we have to find max sum subtree and return sum
here we use portorder traveasal like aproch we get left subtree sum in a nad right subtree sum in b for each subtree
then in currsum add these sum with root->data also and then update ans variable and return currSUm to back stack
as we have pass ans by address so we only have to return ans in main function
*/
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int d){
    Node *temp=new Node;
    temp->data=d;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

int maxSubTreeSumUtil(Node *root, int &ans){
    if(!root) return 0;

    int a=maxSubTreeSumUtil(root->left,ans);
    int b=maxSubTreeSumUtil(root->right,ans);
    int currSum=a+b+root->data;
    ans=max(ans,currSum);
    return currSum;
}

int maxSubtreeSum(Node *root){
    if(!root) return 0;
    int ans=INT_MIN;
    maxSubTreeSumUtil(root,ans);
    return ans;
}
   /*
               1
             /   \
            /     \
          -2       3
          / \     /  \
         /   \   /    \
        4     5 -6     2
    */
int main(){
    Node *root=newNode(1);
    root->left=newNode(-2);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right=newNode(3);
    root->right->left=newNode(-6);
    root->right->right=newNode(2);

    cout<<maxSubtreeSum(root);
    return 0;
}