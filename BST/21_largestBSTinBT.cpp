// Largest BST in a Binary Tree [ V.V.V.V.V IMP ]
// Largest BST
// https://practice.geeksforgeeks.org/problems/largest-bst/1#

/*
Algo:
                             WE have to only figure out these 
#############Forevery subtree of a BST if roots data is gretter than max in its left subtree and 
          roots data is smaller than min on right side then the subtree is BST######################

we mantain a vector to the four things {0=>ISBSt,1=>size,2=>MininLeft,3=>MaxInright}


further we divide the problem into 3subprobles
1. for NULL root we do somethig differet
2. for leaf Node
3. for else nodes

1=> for NULL node 
        every NULL npode is also a BSt but its size is 0 and for our covinience we store int max at min pos and int min at max pos
        that meance our final vector is  =>    {1, 0, INT_MAX,INT_MIN}
2=> for leaf Node:
        every leaf nod eis also a bst abd its size is 1 and its max and min data is alo its self data
        so our vectyor is             =>    {1,1,root->data,root->data}

then we pass recurtiopn to left and right and store the result in l and r vector

3=> for else nodes 

first chech is left subtree of that nod eand right subtree is bst or not and then go forwad
  then check imp
  1). if root data is gretter than max in left and root-> data is smaller than min of right
  #############Forevery subtree of a BST if roots data is gretter than max in its left subtree and 
          roots data is smaller than min on right side then the subtree is BST######################


          return vector accordingly of check if any one of the data are INT_MAX or INT_MIN then we we have 
          to return root data because any one left or right of that tree is NULL so ...
*/


#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};

// vector {0=>isbst,1=>size,2=>lmax,3=>rmax}

vector<int> solve(Node* root){
// node is null
if(!root) return {1,0,INT_MAX,INT_MIN};
// leaf node
if(!root->left and !root->right) return {1,1,root->data,root->data};
// for remaaning all node

vector<int> l=solve(root->left);
vector<int> r=solve(root->right);

if(l[0] and r[0]){
    if(l[3]<root->data and r[2]> root->data){
        int x=l[2];
        int y=r[3];
        if(x==INT_MAX) x=root->data;
        if(y==INT_MIN) y=root->data;
         return {1,l[1]+r[1]+1,x,y};
    }
    return {0,max(l[1],r[1]),0,0};
}

}
int largestBST(Node* root){
    if(!root) return 0;
    vector<int> ans=solve(root);
    return ans[1];
}
           
int main(){
          
  return 0;
}