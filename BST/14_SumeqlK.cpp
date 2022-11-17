// Count pairs from 2 BST whose sum is equal to given value "X"
// Brothers From Different Roots
// similar like two sum problem
/*
Algo:
Two Approches:
1.By using hash map TC:(N) SC : O(N)
a). store all nodes data of tree 1in map
b). iterate over the another tree and check if k-root1->data is present in map of not if present then increase count 
2.By using Normal Tree Travesal and serching
a).do inorder travesal on frist tree and check if k-roots->data is preant in secont tree or not by usinf sercjing
*/
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};
int c=0;

bool isPresentInSecondTree(Node*root2,int newK){
if(!root2) return false;
if(root2->data==newK) return true;
else if(root2->data>newK){
    return isPresentInSecondTree(root2->left,newK);
}
else if(root2->data<newK){
    return isPresentInSecondTree(root2->right,newK);
}
}

void inorderOnfirstTree(Node* root1,Node* root2 ,int k){
if(!root1) return;
inorderOnfirstTree(root1->left,root2,k);
if(isPresentInSecondTree(root2,k-root1->data)) c++;
inorderOnfirstTree(root1->right,root2,k);
}
int countPairs(Node* root1,Node* root2,int k){
    if(!root1 or !root2) return -1;
    inorderOnfirstTree(root1,root2,k);
    return c;
}
           
int main(){
          
  return 0;
}
