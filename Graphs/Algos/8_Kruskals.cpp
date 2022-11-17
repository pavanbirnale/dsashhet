// Kruskals Algorithm || Find Minimum Spanning Tree in Weighted undirected graph
// https://leetcode.com/problems/min-cost-to-connect-all-points/

// Diff between Kruskals and Prims algo : https://www.geeksforgeeks.org/difference-between-prims-and-kruskals-algorithm-for-mst/


/*
Algorithm:
1. Sort all the edges in non-decreasing order of their weight.
2. Pick the smallest edge. Check if it forms a cycle with the spanning-tree formed 
   so far. If the cycle is not formed, include this edge. Else, discard it.
3. Repeat step#2 until there are (V-1) edges in the spanning tree.

This algorithm uses disjoint set union for finding minimum spanning tree

*/


#include<bits/stdc++.h>
using namespace std;

vector<int> par;
vector<int> size;

void make(int v){
    par[v] = v;
} 

int find(int v){
    if(par[v]==v) return v;
    return par[v]=find(par[v]);
}  

void Union(int a,int b){

    a = find(a);
    b = find(b);

    if(a!=b){
        if(size[a]<size[b]) swap(a,b);
        par[b] = a;
        size[a] +=size[b];
    }
}

int kruskals(vector<pair<int,pair<int,int>>> edges)
{
    int totalCost = 0;
    int u,v,wt;
    for(auto &edge : edges){
        wt = edge.first;
        u = edge.second.first;
        v = edge.second.second;
        if(find(u)==find(v)) continue;
        Union(u,v);
        totalCost += wt;
        // cout<<u<<" "<<v<<endl;
    }
    return totalCost;
}

int main(){
    int vrtx,e;
    cin>>vrtx>>e;

    par.resize(vrtx);
    size.resize(vrtx);

    // make independent nodes for dsu
    for(int i = 1;i<=vrtx;i++){
        make(i);
    }

    // input graph
    int u,v,wt;
    vector<pair<int,pair<int,int>>> edges;
    while(e--){
        cin>>u>>v>>wt;
        edges.push_back({wt,{u,v}});
    }
    // sort the edges for geting edge with minimum cost
    sort(edges.begin(),edges.end());

    cout<<kruskals(edges)<<endl;

  return 0;
}

/*
Input : 
6 9
5 4 9
1 4 1
5 1 4
4 3 5
4 2 3
1 2 2
3 2 3
3 6 8
2 6 7
*/