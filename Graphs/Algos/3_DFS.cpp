// Depth First search
#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    vector<vector<int>> graph;
    vector<bool> visited;
    Graph(int vertex){
        graph.resize(vertex);
        visited.resize(vertex);
    }

    void AddEdge(int src,int dest,int wt){
        graph[src].push_back(dest);
        graph[dest].push_back(src);
    }


    void DFS(int vrtx){

        cout<<vrtx<<endl;

        visited[vrtx] = 1;

        for(auto nbr : graph[vrtx]){
            if(!visited[nbr]){
                DFS(nbr);
            }
        }
    }


    void print(){
        int i=0;
        for(auto vrtx : graph){
            cout<<i++<<" -> ";
            for(int nbrs : vrtx){
                cout<<nbrs<<" ";
            }
            cout<<endl;
        }
    }
    void BFS(int vrtx){
        queue<int> q;
        q.push(vrtx);
        visited[vrtx] = 1;
        while(!q.empty()){
            int curr = q.front();
            cout<<curr<<endl;
            q.pop();
            for(auto nbr : graph[curr]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = 1;
                }
            }
        }
    }
};

/*
Given Graph : 
     0_______ 1
    /       /   \
   /       /     \
  4       3_______2
*/


int main(){
    Graph gr(5);
    gr.AddEdge(0,1,1);
    gr.AddEdge(1,2,1);
    gr.AddEdge(2,3,1);
    gr.AddEdge(3,1,1);
    gr.AddEdge(4,0,1);
    gr.BFS(0);
    return 0;
}