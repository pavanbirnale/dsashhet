// Print all possible paths from top left to bottom right of a mXn matrix
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> printPaths(vector<vector<int>> mat,int sr,int sc,int dr,int dc){
if(sr==dr && sc==dc){
     vector<vector<int>> p ={{}};
     return p;
}

    vector<vector<int>> hpaths = {};
    vector<vector<int>> vpaths = {};
    if(sc<dc){
        hpaths = printPaths(mat,sr,sc+1,dr,dc);
    }
    if(sr<dr){
        vpaths = printPaths(mat,sr+1,sc,dr,dc);
    }

    vector<vector<int>> paths = {};
    vector<int> temp1={};
    for(int i=0;i<hpaths.size();i++){
        temp1.push_back(mat[i][sc]);
    }
    paths.push_back(temp1);
    
    vector<int> temp2={};
    for(int i=0;i<vpaths.size();i++){
        temp2.push_back(mat[sr][i]);
    }
    paths.push_back(temp2);
    return paths;
}
           
int main(){  
    vector<vector<int>>mat={{1,2,3},{4,5,6}};
vector<vector<int>>p= printPaths(mat,0,0,2,3);
for(int i=0;i<2;i++){
    for(int j=0;j<3;i++){
    cout<<p[i][j]<<" ";
    }
    cout<<'\n';
}
  return 0;
}