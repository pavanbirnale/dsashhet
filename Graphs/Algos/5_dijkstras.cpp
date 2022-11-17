// Dijkstra's Algorithm - A Single Source Shortest Path Algorithm

// Sortest path between two node of weighted directed Graph

#include<bits/stdc++.h>
using namespace std;

int Dijkstra(int par,int v,int tar,vector<vector<int>> edges){
    priority_queue<pair<int,int>> pq;

    vector<int> dist(v+1,INT_MAX);
    vector<bool> vis(v+1);

    pq.push({0,par});

    while(!pq.empty()){
        auto child  = pq.top();
        pq.pop();

        int childWt = child.first;
        int childVal = child.second;

        if(vis[childVal]) continue;
        vis[childVal] = 1;

// below for loop can change with diff graph input
        for(auto nbr : edges){
            if(nbr[0] == childVal){
                int nbrVal = nbr[1];
                int nbrWt = nbr[2];

// this will be main logic which varies problem to problem
                if(dist[childVal] + nbrWt < dist[nbrVal]){
                    dist[nbrVal] = dist[childVal] + nbrWt;
                    pq.push({nbrWt,nbrVal});
                }

            }
        }

    }
    return dist[tar];
}

int main(){

    return 0;
}