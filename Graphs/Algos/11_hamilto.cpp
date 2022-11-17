// Hamiltonian Path  || Hamiltonian Cycle

 
 
/*
Normal DFS with visited count
*/

#include<bits/stdc++.h>
using namespace std;

    vector<vector<int>> graph;
    vector<bool> vis;
    int visCount = 0;


// 1. Problem First Check if Hamiltonian Path is present or not

    bool isHamiltonianPathPresent(int src,int total){
        if(visCount==total-1){
            return 1;
        }
        vis[src] = 1;
        visCount++;
        for(auto nbr : graph[src]){
            if(!vis[nbr] && isHamiltonianPathPresent(nbr,total)){
                 return 1;
            }
        }
        visCount--;
        vis[src] = 0;
        return 0;
    }
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        graph.resize(N+1);
        vis.resize(N+1);
        for(auto edge : Edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        for(int i=1;i<=N;i++){
            if(!vis[i] && isHamiltonianPathPresent(i,N)) return 1;
        }
        return 0;
    }




// 2.Print all Hamiltonian paths And Cycles
// Below code is only work when we have given that all the nodes are connected and we only have to check weather it will path or cycle


    void isHamiltonianPathPresent(int src,int total,string path,int inputStartNode){
        if(visCount==total-1){
            for(auto nbr : graph(src)){
                if(nbr==inputStartNode){
                    cout<<path<<"*"<<endl;
                    return;
                }
            }
            cout<<path<<"."<<endl;
            return;
        }
        vis[src] = 1;
        visCount++;
        for(auto nbr : graph[src]){
            if(!vis[nbr]){
                isHamiltonianPathPresent(nbr,total,path+to_string(nbr),inputStartNode)
            }
        }
        visCount--;
        vis[src] = 0;
        return 0;
    }
    void printPaths(int N,int M,vector<vector<int>> Edges)
    {
        graph.resize(N+1);
        vis.resize(N+1);
        for(auto edge : Edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        isHamiltonianPathPresent(inputStartNode,total,i,inputStartNode+"");
    }



int main(){
      f();
  return 0;
}