#include<bits/stdc++.h>
using namespace std;












// very very very very important
// this is multisource BFS Algorithm 
// You Solved this queestion again on leetcode on 27-04-2022 By Multisource bfs
// see code on leetcode for seeing changes

// similar question : 01 Matrix  : https://leetcode.com/problems/01-matrix/














/*Algorithm
1. Push all the element of grid the queue have value 2
2. push (-1,-1) as a elivator
3. Iterate over Queue and check four if condition that means for every rotten organge (2) check if fresh organge is present 
   at possition top bottom right left if yes then push that elment to queue
  */       

int orangesRotting(vector<vector<int>>& grid) {
    // initialize a queue of pairs
    queue<pair<int ,int>> q;
    int n=grid.size();
    int m=grid[0].size();
    // push all the elemt of grid to queue if has value 2
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({i,j});
            }
        }
    }
    int count=0;
    // set elivator
    q.push({-1,-1});
    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        // if elivator is reached and size of queue is 1 then pop that elem and break the loop;
        if(i== -1 and j==-1 and q.size()==1){
            q.pop();
            break;
        }
        // if elivator is reached and size is more that 1 then increse count of second
        else if( i==-1 and j ==-1 and q.size() > 0){
            count++;
            q.pop();
            q.push({-1,-1});
        }
        else{
            // check of top bottom right left of every rooten orange
            if(j-1>=0 and grid[i][j-1]==1){
                grid[i][j-1]=2;
                q.push({i,j-1});
            }
            if(i-1>=0 and grid[i-1][j]==1){
                grid[i-1][j]=2;
                q.push({i-1,j});
            }
            if(j+1<m and grid[i][j+1]==1){
                grid[i][j+1]=2;
                q.push({i,j+1});
            }
            if(i+1<n and grid[i+1][j]==1){
                grid[i+1][j]=2;
                q.push({i+1,j});
            }
            q.pop();
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
               return -1;
            }
        }
    }
return count;
}

int main(){
          
  return 0;
}
