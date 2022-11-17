// Convert a normal BST into a Balanced BST
// Convert a normal BST to Balanced BST

/*
Algo:
1st.get all the nodes data into vector
2nd.No need to sort array because it is allredy sorted due to tree is allready bst
3rd. simply dived the vector recursively and set is to root right and left
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M =1e9+7;

struct Node{
    int data;
    Node* left;
    Node* right;
};

void getNodesData(vector<Node*> &Nodes,Node* root){
if(!root) return;
getNodesData(Nodes,root);
Nodes.push_back(root);
getNodesData(Nodes,root);
}

// these is main function each time it only check sart>end condition
// and calculate mid and set root to nodes min
// no need to create new Node
// each time only set start to mid-1 to left subtree and mid+1 to end to right subtree
Node* BuildTree(vector<Node*> &Nodes,int start ,int end){
    if(start>end) return NULL;

    int mid=(start+end)/2;
    Node * root=Nodes[mid];

    root->left=BuildTree(Nodes,start,mid-1);
    root->right=BuildTree(Nodes,mid+1,end);
    return root;
}
Node* BST2BalanceBst(Node* root){
    if(!root) return NULL;
    vector<Node*> Nodes;
    getNodesData(Nodes,root);
    int n=Nodes.size();
    return BuildTree(Nodes,0,n);
}

int main(){
          
  return 0;
}