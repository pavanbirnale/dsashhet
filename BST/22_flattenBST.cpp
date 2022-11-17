// Flatten BST to sorted list
// Article
/*
Algo: TWo ways :
1) Brute force TC : O(N) SC : O(N) 
do inorder traversal and dtore thr result  in a vector and then ctreate new tre from that vector elements;
2)  optimized TC : O(N) SC : O{h};
*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
    }
};

void inorder(Node *root, Node *&prev)
{
    if (!root)
        return;
    inorder(root->left, prev);
    prev->left=NULL;
    prev->right=root;
    prev=root;
    inorder(root->right,prev);
}
Node *flattenBst(Node *root)
{
    if (!root)
        return NULL;

    Node *dummy = new Node(-1);
    Node* prev=dummy;
    inorder(root, prev);
    dummy->left=NULL;
    dummy->right=NULL;
    return dummy->right;

}

int main()
{

    return 0;
}