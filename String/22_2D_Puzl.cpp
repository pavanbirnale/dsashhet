#include<bits/stdc++.h>
using namespace std;
           
int puzzle(int i,int j, string str, vector<vector<char>> grid,int sz,int idx){
    int found =0;
    if(i>=0 and j>=0 and i<=sz and j<=sz and str[idx]==grid[i][j]){
        char temp = str[idx];
        idx++;
        if(idx==sz) found= 1;
        else{
            found+=puzzle(i+1,j,str,grid,sz,idx);
            found+=puzzle(i-1,j,str,grid,sz,idx);
            found+=puzzle(i,j+1,str,grid,sz,idx);
            found+=puzzle(i,j-1,str,grid,sz,idx);
        }
        grid[i][j]=temp;
    }
    return found;
}

int main(){
   vector<vector<char>> grid={
            {'D','D','D','G','D','D'},
            {'B','B','D','E','B','S'},
            {'B','S','K','E','B','K'},
            {'D','D','D','D','D','E'},
            {'D','D','D','D','D','E'},
            {'D','D','D','D','o','G'}
           };  
string str="GEEKSd";
int sz=str.size();
int ans=0;
for(int i=0;i<grid.size();i++){
    for(int j=0;j<grid[0].size();j++){
        ans+=puzzle(i,j,str,grid,sz,0);
    }
}
    cout<<ans;

  return 0;
}