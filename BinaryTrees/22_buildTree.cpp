// https://practice.geeksforgeeks.org/problems/construct-tree-1/1#
// Construct Binary tree from Inorder and preorder traversal
/*
Algo:
1.each time we have to find first number of preorder array in inorder array and 
then divide the inoderder array in two parts one part send to left and anothe sent to right 
if we use linerar seach here then time complexity goes to n^2
so here we use map to srore inoders array values with i beacuse mp[key] returns index thand we need 
while sending min in recursive stackas mp[in[i]]=i;
2.lb ub condition for not overcome them;
3.if 2nd con not present then directly create new node and check leaf node condition
get mid and call recurtion

*/
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data=d;
        left=right=NULL;
    }
};
unordered_map<int,int> mp;
int idx=0;
Node* solve(int in[],int pre[],int lb,int ub){
    if(lb>ub) return NULL;
    Node* res=new Node(pre[idx]);
    if(lb==ub) return res;
    int mid=mp[res->data];
    res->left=solve(in,pre,lb,mid-1);
    res->right=solve(in,pre,mid+1,ub);
    return res;
}
Node* BuildTree(int in[],int pre[],int n){
    for(int i=0;i<n;i++){
        mp[in[i]]=i;
    }
    Node* root=solve(in,pre,0,n-1);
    return root;
}
int main(){
          
  return 0;
}