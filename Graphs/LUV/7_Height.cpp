// Find Height and Depth of Binary Tree by Depth first Search*-
 /*
 Height Of Tree : It is defined As the total number of node present in the path between longest leaf node and the curr node;
 Depth of Tree : It is defined As the number of nodes present in the path between root node of tree to curr Node 
 */




// This code is only for tree which is given as acyclic graph







 #include<bits/stdc++.h>
 using namespace std;
 
 int depth[10];
 int height[10];

 void dfs(int vrtx, int par, vector<vector<int>> tree){

     for(auto child : tree[vrtx]){
         if(child==par) continue;
         depth[child] = depth[par] + 1;
         dfs(child,vrtx,tree);
         height[child] = max(height[child]+1,height[vrtx]);
     }
 }

 pair<int,int> heightAndDepth(vector<vector<int>> tree){
     dfs(1,0,tree);
     int h = *max_element(depth,dept+10);
     int d = *max_element(height,height+10);
     return {h,d};
 }


 int main(){

     return 0;
 }