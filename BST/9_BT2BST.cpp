//Convert Binary tree into BST
/*
Algo:
1st.Get all Nodes data to an array by inorder traversal
2nd. sort that array
3rd. by performing in order traversal again stre the data of array one by one using inorder traversal
*/
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

void getNodesData(vector<int> &Nodes,Node* root){
if(!root) return;
getNodesData(Nodes,root);
Nodes.push_back(root->data);
getNodesData(Nodes,root);
}
void restoreNodesData(vector<int> Nodes,Node* &root,int &idx){
if(!root) return;
restoreNodesData(Nodes,root,idx);
root->data=Nodes[idx++];
restoreNodesData(Nodes,root,idx);
}
Node* BinartTree2BST(Node* root){
if(!root) return NULL;
vector<int> Nodes;
getNodesData(Nodes,root);
sort(Nodes.begin(),Nodes.end());
int idx=0;
restoreNodesData(Nodes,root,idx);
return root;
}
           
int main(){
          
  return 0;
}