// flood Fill || Graph matrix problem

#include<bits/stdc++.h>
using namespace std;
void dfs(int i,int j,int initialColor,int newColor,veccor<vector<int>> &image){
    int n = image.size();
    int m = image[0].size();

    // boundary condition cheching
    if(i<0 || j<0 || i>=n ||j>=m) return;
    if(initialColor != image[i][j]) return;

    // changeing initial color with newColor
    image[i][j] = newColor;

    // Blind Recursive calls
    dfs(i-1,j,initialColor,newColor,image);
    dfs(i,j-1,initialColor,newColor,image);
    dfs(i+1,j,initialColor,newColor,image);
    dfs(i,j+1,initialColor,newColor,image);
}
vector<vector<int>> floodFill(int sr,int sc,int newColor,vector<vector<int>> image){
    int initialColor = image[sr][sc];
    if(initialColor != newColor) dfs(sr,sc,initialColor,newColor,image);
    return image;
}
int main(){

    return 0;
}