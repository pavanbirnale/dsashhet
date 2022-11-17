// Rat in a Maze Problem - I || Flood Fill
// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#

// Pepcoding
// https://www.youtube.com/watch?v=R1URUB6_y2k

/* Algo : 
blindly pass the recursion in all directions and get result 
in base case if row and col get out of bond then return from that possition 
or if that cell is allready visited then also return 
or there is an obstacle then also retry from that pos

and is we reach to n-1 possition then that is a valid path so push it to vector
*/
#include<bits/stdc++.h>
using namespace std;

// Globally declare answer vector
vector<string> paths={};


void mazePaths(vector<vector<int>>m,int row,int col,int n,string preAns,vector<vector<bool>>&vis){

// this below can be written separately in bool is safeNvalid function also
if(row<0 || col<0 || row==n || col==n || vis[row][col] || m[row][col]==0){
    return;
}

// if rat reach at last possition then return by pushing prev ans to paths
if(row==n-1 && col==n-1){
    paths.push_back(preAns);
    return;
}

    // setting visited 
    vis[row][col]=true;

    // passing recursion to all direction
    mazePaths(m,row-1,col,n,preAns+"U",vis);
    mazePaths(m,row+1,col,n,preAns+"D",vis);
    mazePaths(m,row,col-1,n,preAns+"L",vis);
    mazePaths(m,row,col+1,n,preAns+"R",vis);
    vis[row][col]=false;

}
int main(){
    vector<vector<int>> m={{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}};
         int n=4;
    vector<vector<bool>> vis(n,vector<bool>(n,false));
    mazePaths(m,0,0,n,"",vis);

    for(string s : paths){
        cout<<s<<" ";
    }
}