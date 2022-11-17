// Duplicate subtree in Binary Tree
// Check if a Binary Tree contains duplicate subtrees of size 2 or more [ IMP ]
// important
/*
here we use string to check duplicates subtrees
after wesinting each subtress left and right part strore result in map;
elilimintor is use to avoid NULL case smae string valus
*/
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

unordered_map<string,int> mp;
string solve(Node* root){
    if(!root) return "$";
    string s="";
    if(!root->left and !root->right) {
        s=to_string(root->data);
        return s;
    }
    s=s+to_string(root->data);
    s=s+solve(root->left);
    s=s+solve(root->right);
    mp[s]++;
    return s;
}
bool dupSub(Node* root){
    solve(root);
    for(auto itr:mp){
        if(itr.second>=2) return true;
    }
    return false;
}
           
int main(){
          
  return 0;
}