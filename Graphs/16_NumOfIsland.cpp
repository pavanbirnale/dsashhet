// Number Of Islands || Count the number of disconnected components in graph
// find the disconnected components count
 
 
#include<bits/stdc++.h>
using namespace std;
           
class Solution {
public:
    void dfs(int i,int j,int n,int m,vector<vector<char>> &grid){
        if(i<0 || j<0 || i>=n ||j>=m) return;
        
        if(grid[i][j]=='0') return;
        
        grid[i][j] = '0';
        
        dfs(i-1,j,n,m,grid);
        dfs(i+1,j,n,m,grid);
        dfs(i,j-1,n,m,grid);
        dfs(i,j+1,n,m,grid);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int ct = 0;
        int n =grid.size();
        int m =grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1') {
                    ct++;
                    dfs(i,j,n,m,grid);
                }
            }
        }
        return ct;
    }
};
           
int main(){
      f();
  return 0;
}