/*
Algo:
1.problem same like tranfrom tree into sum tree here we use same logic 
*/


#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};
bool f=1;
int solve(Node* root){
    if(!root) return 0;
    // Condition given in problem that if it is lr=eaf node then it is always sum tree
    if(!root->left and !root->right) return root->data;
    //  this is for always going to back stack when we reach such condition where f is false
    if(f==0) return 0;
    int a=solve(root->left);
    int b=solve(root->right);
    if(a+b!=root->data) return f=0;
    return a+b+root->data;

}
bool isSumTree(Node* root){
    f=1;
    solve(root);
    return f;
}
           
int main(){
          
  return 0;
}