// maximum sum path in bimary tree
// Sum of Nodes on the Longest path from root to leaf node 
// Sum of the Longest Bloodline of a Tree (Sum of nodes on the longest path from root to leaf node)
/*
Algo:
here what we have to do is to find the find the such longest path with maximum sum path must 
be longest whatever the sum it doesn't matter
so first of all we pash one pointer to left and another to right parts of the each subtree recursively
and get the vector values and store them into a and b
           //here rater than a vector we acn also used pair but for making things simpale we have used vector
then compare the hightes that means veactor[0] value for eack subterss from left part and right part 
if a[0] is gretter then return that a[0]+1 as height and a[1] with addition of curr root data to back stack
same for b also
and in else part if heights of the subtrees are same then comare max of there sums and return it
in main function we have to anly return a[1] that means sum;
*/
#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node* left;
  Node* right;
  Node(int d){
      data=d;
      left=right=NULL;
  }
};
vector<int> solve(Node* root){
  if(!root) return {0,0};

  vector<int> a=solve(root->left);
  vector<int> b=solve(root->right);

  if(a[0]>b[0]) return{a[0]+1,a[1]+root->data};
  else if(a[0]<b[0]) return {b[0]+1,b[1]+root->data};
  else return {a[0]+1,max(a[0],b[0])+root->data};
}
int maxSum(Node* root){
  vector<int> ans=solve(root);
  return ans[1];
}

           
int main(){
          
  return 0;
}