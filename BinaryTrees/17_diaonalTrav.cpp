// Diagnol Traversal of a Binary tree;
// Very easy algo:
/*
here we have to traverse digonaly
              1
            /   \
          2      3
         / \    / \
        9   0  6   4
         \
          10
        output: 1 3 4
                2 0 6
                9 10
like these
Algo:
from root only to toward right subtree and if left node is present then push itinto queue
and when we reach at such node where right is null then take queues front as new node
and repete these condition untill queue become empty
*/
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};
vector<int> digonalTraversal(Node* root){
    vector<int> ans;
    if(!root) return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* t=q.front();
        q.pop();
        while(t){
           if(t->left) q.push(t->left);
           ans.push_back(t->data);
           t=t->right;
        }
    }
    return ans; 
}

           
int main(){
          
  return 0;
}