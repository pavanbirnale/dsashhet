// find Connected Component in Graph by Depth First search

// Number of Provinces-     https://practice.geeksforgeeks.org/problems/number-of-provinces/1/#

/*
Algorithm : 
It is quit simple that we get the connected component from visited array only that 
use for loop on the visited array and cll the dfs function to every unvisited node and count that chance
*/

#include<bits/stdc++.h>
using namespace std;

// Here is code for depth First search for adj matrix representation
void DFS(int src,vector<vector<int>> adj,vector<bool> &vis){

    vis[src] = 1;
    
    for(int nbr = 0; nbr<adj.size(); nbr++){
        if(adj[src][nbr] && !vis[nbr]){
            DFS(nbr,adj,vis);
        }
    }
}

int ConnectedComp(vector<vector<int>> adj , int v){

    vector<bool> vis(v,0);
    int ct = 0;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            DFS(i,adj,vis);
            ct++;
        }
    }
    return ct;
}

int main(){

    return 0;
}














// print connected component in Graph
// Slight Changes in Above code





vector<vector<int>> ans;
vector<int> curr;
void DFS(int src,vector<vector<int>> adj,vector<bool> &vis){

    vis[src] = 1;
    curr.push_back(src);
    for(int nbr = 0; nbr<adj.size(); nbr++){
        if(adj[src][nbr] && !vis[nbr]){
            DFS(nbr,adj,vis);
        }
    }
}

int ConnectedComp(vector<vector<int>> adj , int v){

    vector<bool> vis(v,0);
    int ct = 0;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            curr.clear();
            DFS(i,adj,vis);
            ans.push_back(curr);
            ct++;
        }
    }
    return ct;
}
