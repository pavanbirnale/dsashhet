// perfect binary Tree
// Check if all leaf nodes are at same level or not
#include<bits/stdc++.h>
using namespace std;

bool ans;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data=d;
        left=right=NULL;
    }
};

void height(Node *root,int h, int &ma){
    // check for null condition
    if(!root) return;
    // check for ans=0 these is for treturn from back stack everytime whech conditon get fals eat least one time
    if(ans==0) return;
    // if node is leaf node then only checki for height 
    if(!root->left and !root->right){
        // if node is first leaf node then change ma from to -1 to curr height
        if(ma==-1){
            ma=h;
        }
        // if max height and curr height is not same then the tree is not perfect tree
        else if(h!=ma){
            ans=0;
        }
        // afer these conditions simply return from recursive stack
        return;
    }
    // if the node is not a leaf node then go  to left and right
    height(root->left,h+1,ma);
    height(root->right,h+1,ma);
}
bool isPerfectTree(Node *root){
    int ma=-1;
    int h=0;
    ans=true;
    height(root,h,ma);
    return ans;
}
           
int main(){
          
  return 0;
}