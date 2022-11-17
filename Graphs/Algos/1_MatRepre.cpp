// Matrix Representation of Graph

#include<bits/stdc++.h>
using namespace std;

class Graph{

    public:
    vector<vector<int>> graph;

    Graph(int vertex){
        graph.resize(vertex,vector<int>(vertex));
    }

    void AddEdge(int src , int dest , int wt){
        graph[src][dest] = wt;
        graph[dest][src] = wt;
    }

    void print(){
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph.size();j++){
                // if(graph[i][j]==1){
                    // cout<<i<<" -> "<<j<<endl;
                    cout<<graph[i][j]<<" ";
                // }
            }
            cout<<endl;
        }
    }
};


/*
0 1 0 0 0 
1 0 1 1 0 
0 1 0 1 0 
0 1 1 0 1 
0 0 0 1 0 
*/

int main(){
    Graph gr(5);
    gr.AddEdge(0,1,1);
    gr.AddEdge(1,2,1);
    gr.AddEdge(2,3,1);
    gr.AddEdge(3,1,1);
    gr.AddEdge(4,3,1);
    gr.print();
    return 0;
}