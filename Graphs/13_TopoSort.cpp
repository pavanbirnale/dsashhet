// 13_ Topological sort in Graph
/*
Problems : 
1. Course Shedueling  => https://leetcode.com/problems/course-schedule/    
 Or prerequisite Tasks => https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/
2. Course Shedueling ii => https://leetcode.com/problems/course-schedule-ii/
2. Alians Dict => https://practice.geeksforgeeks.org/problems/alien-dictionary/1#
*/

/*
Def : A permutation of vertices in which for all the edges (u,v) u must appears before v.

so for geting topological sort we simply do DFS + postorder Traversal
why not preorder? and why use of stack is need explain in video
*/
 
 
#include<bits/stdc++.h>
using namespace std;

stack<int> st;
vecctor<bool> vis;
void dfs(int par,vector<int> edges[]){
    vis[par] = 1;

    for(auto nbr : edges[par]){
        if(!vis[nbr]){
            dfs(nbr,edges);
            vis[nbr] = 1;
        }
    }
    // here in change from  normal dfs we push par in stack by post order
    st.push(par);
}
vector<int> topoSort(int v,vector<int> edges[]){
    vector<int> ans;
    vis.resize(v,0);
    for(int i=0;i<v;i++){
        if(!vis[i]) dfs(i,edges);
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
           
int main(){
      f();
  return 0;
}