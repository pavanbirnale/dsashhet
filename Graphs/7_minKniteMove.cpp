// Minimum Knight Moves to Reach Target

/*
// Normal BFS algorithm:
*/
#include<bits/stdc++.h>
using namespace std;

int size,tarX,tarY;
vector<vector<bool>> vis;
vector<vector<int>> lev;

vector<pair<int,int>> moves = {{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1}};

bool isValid(int x,int y){
    if(x<0 || y<0 || x>= size || y>=size) return 0;
    return 1;
}

int BFS(int sr,int sc){
    if(tarX == sr && tarY == sc) return 0;
    queue<pair<int,int>> q;
    q.push({sr,sc});
    vis[sr][sc] = 1;

    while(!q.empty()){
        pair<int,int> curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;

        for(auto move : moves){
            int currX = move.first + x;
            int currY = move.second + y;

            if(isValid(currX,currY) && !vis[currX][currY]){
                q.push({currX,currY});
                vis[currX][currY] = 1;
                lev[currX][currY] = lev[x][y] + 1;
            }
        }
        if(lev[tarX][tarY] != 0) break;
    }
    return lev[tarX][tarY];
    
}
int minMoves(vector<int> kp,vector<int> tp,int n){
    tarX = tp[0]-1;
    tarY = tp[1]-1;
    size = n;
    vis.resize(n,vector<bool>(n,0));
    lev.resize(n,vector<int>(n,0));
    return BFS(kp[0]-1,kp[1]-1);
}

int main(){
    int n = 6; //chessbord size
    vector<int> knightPos = {1,1};
    vector<int> TargetPos = {4,5};

    cout<<minMoves(knightPos,TargetPos,n);
    return 0;
}