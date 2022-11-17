// Breadth First Search

/*
Breadth First search Algorithm is mainly used in such Problems where the given graph is unweighted or have equal wight
It is used for finding Shotest Path between Two Nodes

It definitely Gives shortest Path between Two Node but it may or may not be Optimal in terms of cost / Weight
*/

#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    vector<vector<int>> graph;
    vector<bool> vis;
    Graph(int s){
        graph.resize(s);
        vis.resize(s);
    }

    void AddEdge(int u,int v,int wt){
        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    void BFS(int vrtx){
        queue<int> q;
        q.push(vrtx);
        vis[vrtx] = 1;
        while(!q.empty()){
            int curr = q.front();
            cout<<curr<<endl;
            q.pop();
            for(auto nbr : graph[curr]){
                if(!vis[nbr]){
                    q.push(nbr);
                    vis[nbr] = 1;
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