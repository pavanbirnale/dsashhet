// https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1#
// Distance of nearest cell having 1 in a binary matrix

// Algo Similer Like  Min time require to rot all oranges
/*
1.create one 2d vector with INT_max value at every index
2.then change the value at index i and j for which grid has value 1 to the 0 and push that to queue;
 that means for every 1 its minimun distance to nearest one wiil be one;
3.untill the queue become empty move to all  the direction to up down right left and check if its distance is greter 
than [i][j]+1 th distance if yes then change  [i-1][j]    [i][j-1]   [i+1][j]   [i][j+1] to [i][j]+1
*/
#include<bits/stdc++.h>
using namespace std;
    vector<vector<int>>nearest(vector<vector<int>>grid)
	{
    int r=grid.size();
    int c=grid[0].size();
    int m=INT_MAX;
    queue<pair<int,int>> q;
    vector<vector<int>> ans(r,vector<int>(c,m));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]==1){
                ans[i][j]=0;
                q.push({i,j}); 
            }
        }
    }
    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        if(i-1>=0 and ans[i][j]+1<ans[i-1][j]){
            ans[i-1][j]=ans[i][j]+1;
            q.push({i-1,j});
        }
        if(j-1>=0 and ans[i][j]+1< ans[i][j-1]){
            ans[i][j-1]=ans[i][j]+1;
            q.push({i,j-1});
        }
        if(i+1<r and ans[i][j]+1<ans[i+1][j]){
            ans[i+1][j]=ans[i][j]+1;
            q.push({i+1,j});
        }
        if(j+1<c and ans[i][j]+1< ans[i][j+1]){
            ans[i][j+1]=ans[i][j]+1;
            q.push({i,j+1});
        }
        q.pop();
    }
    return ans;
}

int main(){
  return 0;
}