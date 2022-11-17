// Minimum time taken by each job to be completed given by a Directed Acyclic Graph
// this is code of course shedueling - ii only difference is that seq array added newly
 
 
#include<bits/stdc++.h>
using namespace std;

    vector<int> vis;
    vector<vector<int>> graph;
    vector<int> completed;
    vector<int> seq;
    int total;
    
    void bfs(vector<int> &independent){
        queue<int> q;
        for(int i=0;i<graph.size();i++){
            if(independent[i]==0){
                q.push(i);   
                seq[i] = 1;;
            }
        }
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            completed.push_back(curr);
            for(auto nbr : graph[curr]){
                if(--independent[nbr]==0){
                    q.push(nbr);
                    seq[nbr] = seq[curr] + 1;
                }
            }
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        vis.resize(numCourses);
        seq.resize(numCourses);

        vector<int> independent(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            ++independent[prerequisites[i][1]-1];
            graph[prerequisites[i][0]-1].push_back(prerequisites[i][1]-1);
        }
        bfs(independent);
        return numCourses==completed.size();
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if(canFinish(numCourses,prerequisites)) return completed;
        else return {};
    }

int main(){
      vector<vector<int>> edges = {
          {1,3},{1,4},{1,5},{2,3},{2,8},{2,9},{3,6},{4,6},{4,8},{5,8},{6,7},{7,8},{8,10}
      };
      vector<int> ans = findOrder(10,edges);
      for(int i=0;i<10;i++){
          cout<<seq[i]<<" ";
      }
  return 0;
}