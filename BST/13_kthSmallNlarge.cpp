// Kth largest element in BST and k-th smallest element in BST
/*
Algo:
Two approches :
1. TC : O(N) SC: O(N)
2. TC : O(K) SC: O(1)

1st:  TC : O(N) SC: O(N)
    a).Inorder travers the bst and store the results in an vector first
    b).no need to sord the vector because it is allready sorted
    c).then for smallest return vector[k-1]th element and for
       largest return vector[n-k]th element
       ------these solution is present ion gfg my solution-----------
2nd: TC : O(K) SC: O(1)
a).For smallest element: take a counter to comre with k and for smaller element travers by using
   inorder and simulteniously compare c with k if it reaches to k then return that element
a) For largest element: similarly take a counter and traverse here by ushing reverse inorder algo
*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;
};


// kth smallest
int c = 1;
void kthSmallestElmeUtil(Node *root, int k, int &ans)
{
  if (!root)
    return;
  kthSmallestElmeUtil(root->left, k, ans);
  if (c == k)
  {
    ans = root->data;
    c++;
    return;
  }
  else
    c++;
  kthSmallestElmeUtil(root->right, k, ans);
}
int KthSmallestElement(Node *root, int K)
{
  if (!root)
    return -1;
  int ans = -1;
  kthSmallestElmeUtil(root, K, ans);
  return ans;
}




// kth largest
    int c=1;
        void getBstArray(Node* root,int k,int &ans){
        if (!root)
    return;
  getBstArray(root->right, k, ans);
  if (c == k)
  {
    ans = root->data;
    c++;
    return;
  }
  else
    c++;
  getBstArray(root->left, k, ans);
    }
    int kthLargest(Node *root, int K)
    {
          if (!root)
    return -1;
  int ans = -1;
  getBstArray(root, K, ans);
  return ans;
    }


int main()
{

  return 0;
}