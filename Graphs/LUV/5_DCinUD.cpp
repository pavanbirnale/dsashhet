// Detect cycle in undirected Graph

// Algorithm is simple that we only have to check wheather we can go to any previously visited node
// rahter than parent via recursive call if we go to such node then their is must a cycle is present

#include<bits/stdc++.h>
using namespace std;
bool DFS(int src ,int par, vector<int> adj[],vector<bool> vis){
    vis[src] = 1;
    bool isCyclePresent = 0;
    for(auto nbr : adj[src]){

        // checking for node weather it is visited and if it is parent then continue from that node
        if(vis[nbr] && nbr == par){
            continue;
        }
        // else if node is previously visited then cycle is present then return true
        if(vis[nbr]) return 1;
        isCyclePresent |= DFS(nbr,src,adj,vis);
    }
    return isCyclePresent;
}

bool isCycleDetected(vector<int> adj[],int v){

    vector<bool> vis(v,0);

    for(int i=0;i<v;i++){

        // while starting if it is not visited and from that node we get true then return true
        if(!vis[i] && DFS(i,0,adj,vis)){
            return 1;
        }
    }
    return 0;
}
int main(){

    return 0;
}