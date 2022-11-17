// Print all "K" Sum paths in a Binary tree
// https://www.geeksforgeeks.org/print-k-sum-paths-binary-tree/
// article only

/*
firstly push all the node to vector until we reached any one of the leaf node
whrch we rweched any one of leaf node then from that add up th array elment and 
check weater the sum is k or not and print them
and finly pop out elements from vector
*/
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

void KpathwithsumeqlK(Node* root,vector<int> & paths,int k){
    if(!root) return;
    paths.push_back(root->data);
    KpathwithsumeqlK(root->left,paths,k);
    KpathwithsumeqlK(root->right,paths,k);

    int sum=0;
    for(int i=paths.size()-1;i>=0;i--){
        sum+=paths[i];
        if(sum==k){
            for(int j=i;j<paths.size();j++){
                cout<<paths[i]<<" ";
            }
            cout<<"\n";
        }
    }
    paths.pop_back();

}
           
int main(){
    Node* root;
    vector<int> paths;
    KpathwithsumeqlK(root,paths,5);
  return 0;
}