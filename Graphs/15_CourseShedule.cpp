// Course Shedulling || prerequisite Tasks

// 1. Course Shedueling  => https://leetcode.com/problems/course-schedule/    
//  Or prerequisite Tasks => https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/

/*
We have given vector of pairs of courses for every pair the course at pair of first should be completate before taking second
that means the course second is depend on course first
*/

/*
Algorithm : 
This Problem is aldo depend on topological sort but e]we not do it by using that
we use Another approach in which we maintains another independent array in we we takes count of dependent courses

and at start and every time in que we push the course with zero value that means that are indepent on all the others

and incress the count of completed courses and at last we only check is the total given courses and we done are same or not
that is our answer
*/

 
 
#include<bits/stdc++.h>
using namespace std;
           
class Solution {
public:
    vector<int> vis;
    vector<vector<int>> graph;
    int completedC = 0;


    void bfs(vector<int> &independent){
        queue<int> q;
        // here we push all the independent courses first
        for(int i=0;i<graph.size();i++){
            if(independent[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            completedC++;
            for(auto nbr : graph[curr]){
                // check every time weather the nbr course is completed or not
                if(--independent[nbr]==0){
                    q.push(nbr);
                }
            }
        }
    }
    
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        vis.resize(numCourses);
        vector<int> independent(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            // incress depent courses count
            ++independent[prerequisites[i][0]];
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        bfs(independent);
        return numCourses==completedC;
    }
};
           
int main(){
      f();
  return 0;
}