// Multisource BFS Algorithm

// problem based on above algorithm
// 01 Matrix : https://leetcode.com/problems/01-matrix/
// Rotating Oranges : https://leetcode.com/problems/rotting-oranges/

// this Algorithm is similar like normal BFS only difference is that while pushing the single node to queue 
// push all the nodes with matching condition


//  Date : 27/04/2021 
//  video : https://www.youtube.com/watch?v=xvi8PqRrAyU&list=PLauivoElc3ghxyYSr_sVnDUc_ynPk6iXE&index=15

class Solution {
public:
    
    int n,m;
    vector<vector<int>> vis;
    vector<vector<int>> lev;
    vector<pair<int,int>> moves = {{0,-1},{-1,0},{0,1},{1,0}};
    

    // validity condition
    bool isValid(int x,int y){
        if(x<0 || y<0 || x>= n || y>= m) return 0;
        return 1;
    }
    
    void multiSourceBfs(int sr,int sc,vector<vector<int>>& mat){
        queue<pair<int,int>> q;

        // here pushing all the nodes with zero value
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j]==0) {
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        // else all similar
        while(!q.empty()){
            pair curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;
            
            for(auto move : moves){
                int nx = move.first + x;
                int ny = move.second + y;
                
                if(!isValid(nx,ny)) continue;
                if(vis[nx][ny]) continue;
                
                q.push({nx,ny});
                vis[nx][ny] = 1;
                lev[nx][ny] = lev[x][y] + 1;
            }
            
        }
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    
        n = mat.size();
        m = mat[0].size();
        vis.resize(n,vector<int>(m,0));
        lev.resize(n,vector<int>(m,0));
        
        multiSourceBfs(0,0,mat);
        
        return lev;
    }
};