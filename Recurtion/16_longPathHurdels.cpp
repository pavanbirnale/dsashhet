// Longest Possible Route in a Matrix with Hurdles
// similer like land mines
// https://www.geeksforgeeks.org/longest-possible-route-in-a-matrix-with-hurdles/

#include<bits/stdc++.h>
using namespace std;

int lPath;
vector<vector<int>> mat={ { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                          { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
                          { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };

bool isvalid(int sr,int sc){
    if(sr<0 || sc<0 || sr >= mat.size() || sc >= mat[0].size() ){
        return false;
    }
    return true;
}

bool isSafe(vector<vector<bool>>visited,int sr,int sc){
    if(visited[sr][sc] || mat[sr][sc]== 0){
        return 0;
    }
    return 1;
}

void LongestPathUtil(int lpsf,int sr,int sc,vector<vector<bool>> visited,int dr,int dc ){

    if(sr==dr-1 && sc == dc-1){
        if(lPath<lpsf){
            lPath=lpsf;
        }
        return;
    }

    if(!isvalid(sr,sc) || !isSafe(visited,sr,sc)) return;

    visited[sr][sc] = 1;
    LongestPathUtil(lpsf+1,sr-1,sc,visited,dr,dc);
    LongestPathUtil(lpsf+1,sr,sc-1,visited,dr,dc);
    LongestPathUtil(lpsf+1,sr+1,sc,visited,dr,dc);
    LongestPathUtil(lpsf+1,sr,sc+1,visited,dr,dc);
    visited[sr][sc] = 0;

}

int LongestPath(){
    lPath=0;

    int dr = mat.size();
    int dc = mat[0].size();

    vector<vector<bool>> visited(dr,vector<bool>(dc,0));
    LongestPathUtil(1,0,0,visited,dr,dc);
    return lPath;
}
           
int main(){
    cout<<LongestPath();
  return 0;
}