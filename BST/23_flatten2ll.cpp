// Flaten Bst to Linked List

 
 
#include<bits/stdc++.h>
using namespace std;
           
// REverse postorder Type

Node* prev = NULL;
void flatten(Node *root)
{
    if(!root) return;
    flatten(root->right);
    flatten(root->left);
    root->right = prev;
    root->left = NULL;
    
    prev = root;
}
           
int main(){
      f();
  return 0;
}