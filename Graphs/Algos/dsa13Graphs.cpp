// // Graph Representation :

// // 1. Adjecency Matrix : 


// #include <iostream>
// using namespace std;
 
// int main()
// {
 
//     int n, m;
//     cin >> n >> m ;
//     int adjMat[n + 1][m + 1];
//     for(int i = 0; i < m; i++){
//         int u , v ;
//         cin >> u >> v ;
//         adjMat[u][v] = 1 ;
//         adjMat[v][u] = 1 ;
//     }
     
     
//     return 0;
// }




// // 2. Adjecency List by vector: 


// #include<bits/stdc++.h>
// using namespace std;
           
// void addEdge(vector<int> adj[],int u,int v){
//     adj[u].push_back(v);
//     adj[v].push_back(u);
// }
// void PrintGraph(vector<int> adj[]){
// int V=5;
// for (int v = 0; v < V; ++v) {
//     cout<<v<<" ";
//         for (auto x : adj[v])
//             cout << "-> " << x;
//         printf("\n");
//     }
// }
           
// int main(){
//     vector<int> adj[5];
//     addEdge(adj, 0, 1);
//     addEdge(adj, 0, 4);
//     addEdge(adj, 1, 2);
//     addEdge(adj, 1, 3);
//     addEdge(adj, 1, 4);
//     addEdge(adj, 2, 3);
//     addEdge(adj, 3, 4);
//     PrintGraph(adj);
//   return 0;
// }

// 3. Adjecency List By class :

class Edge{
    public :
    int src;
    int des;
    int wt;

    Edge(int src,int des,int wt){
        this->src = src;
        this->des = des;
        this->wt = wt;
    }

    void AddEdge(int src,int des,int wt,vector<Edge> Graph){
        Edge newEdge = new Edge(src,des,wt);
        Graph[src] = newEdge;
    }
    void printGraph(vector<Edge> Graph){
        for(auto i : Graph){
            cout<<i.src<<" "<<i.des<<" "<<i.wt<<endl;
        }
    }
};

int main(){
    vector<Edge> Graph(10);
    Edge edj;
    edj.AddEdge(1,2,0,Graph);
    edj.AddEdge(1,3,0,Graph);
    edj.AddEdge(1,4,0,Graph);
    edj.AddEdge(2,1,0,Graph);
    edj.AddEdge(2,3,0,Graph);
    edj.AddEdge(3,2,0,Graph);
    edj.AddEdge(3,1,0,Graph);
    edj.AddEdge(3,4,0,Graph);
    edj.AddEdge(4,3,0,Graph);
    edj.AddEdge(4,1,0,Graph);
}