// Detect Cycle in Directed Graph

/*
In undirected Graph we follow algorithm that if we again go to such node which is previously visited then their is cycle present in graph.
This Algo works there because in undirected Graph the node are connected bidirectionally

But, In directed graph only one way connection is present so,above approach gives wrong result and we have to find another approach
*/

/*
Algorithm : 

Along with the visited array we also maintains RecStack Array and use like backTracking that means after visiting node set recStack[node] = 1;
and while leaving it set recStack to false
*/

#include<bits/stdc++.h>
using namespace std;

vector<bool> vis,recStack;
bool dfs(int src,vector<int> &adj){
    if(!vis[src]){
        vis[src] = 1;
        recStack[src] = 1;

        for(auto nbr : adg[src]){
            if(!vis[nbr] && dfs(nbr,adj)) return 1;
            else if(recStack[nbr]) return 1;
        }
    }
    recStack[src] = 0;
    return 0;
}

bool detectCycle(int v,vector<vector<int>> &adj){
    vis.resize(v);
    recStack.resize(v);

    for(int vrtx = 0; vrtx < v; vrtx++){
        if(!vis[vrtx] && dfs(vrtx,adj)){
            return 1;
        }
    }
    return 0;
}


int main(){

    return 0;
}