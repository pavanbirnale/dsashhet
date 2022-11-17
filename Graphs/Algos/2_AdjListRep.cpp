// Graph Representation by Adjecency List

#include<bits/stdc++.h>
using namespace std;

class Graph{

    public:
    vector<vector<pair<int,int>>> graph;

    Graph(int vertex){
        graph.resize(vertex);
    }

    void AddEdge(int src,int dest,int wt){
        graph[src].push_back({dest,wt});
        graph[dest].push_back({src,wt});
    }

    void print(){
        int i = 0;
        for(auto vrtx : graph){
            cout<<i++<<" -> ";
            for(pair<int,int> nbrs : vrtx){
                cout<<nbrs.first<<" ";
                // cout<<nbrs.first<<" "<<nbrs.second<<" || ";

            }
            cout<<endl;
        }
    }
};


/*
0 -> 1     
1 -> 0 2 3 
2 -> 1 3   
3 -> 2 1 4 
4 -> 3
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