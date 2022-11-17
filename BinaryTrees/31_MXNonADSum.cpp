// Maximum Sum of nodes in Binary tree such that no two are adjacent 
// Maximum sum of Non-adjacent nodes
// dp Dinamic Programming
// https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1/#

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left,*right;
};

unordered_map<Node *,int> dp;
int maxNonADjSum(Node *root){

// check for NULL condition
if(!root) return 0;

// check is node is present in dp or not
if(dp[root]) return dp[root];

// ek bar include ek bar exclude
int inc = root->data;
if(root->left){
    inc+=maxNonADjSum(root->left->left);
    inc+=maxNonADjSum(root->left->right);
}
if(root->right){
    inc+=maxNonADjSum(root->right->left);
    inc+=maxNonADjSum(root->right->right);
}
int exc = maxNonADjSum(root->left)+maxNonADjSum(root->right);
dp[root]=max(inc,exc);
return dp[root];
}
           
int main(){
          
  return 0;
}