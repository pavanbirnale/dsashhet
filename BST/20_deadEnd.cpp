// Check whether BST contains Dead end

/*
Algo :
Two approches:
1. TC : O(N) SC : O(N) By using Hashing
    here use two unorderd maps one for store all the leaf nodes and another for allthe nodes of tree
    here for every leaf node if its previous and next element is allredy present in tree then that node is dead node 
    that mense for 8 node if 7 and 9 is present then 8 would be leaf node
2. TC : O(N) SC : O(1) by ushing concept of renges
    here we mentane range of upperbound and lowerBound for each and every node
    if this ranges are get equal then that node is Dead Node
    from that return true
*/
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

bool solve(Node* root,int lb,int ub){
if(!root) return false;
if(lb==ub) return true;
return solve(root->left,lb,root->data-1) or solve(root->right,root->data+1,ub);
}

bool isDeadPresent(Node* root){
    if(!root) return false;
    return solve(root,1,INT_MAX);
}
           
int main(){
          
  return 0;
}