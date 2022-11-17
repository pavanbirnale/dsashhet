// m Coloring Problem
// M-Coloring Problem 
/*
Algo:
here what we have to do is w ahve given a graph having some nodes and we have to try to
colors the nodes if we successfully gives colors to node then return true 
by maintainig the condition that no two adjesent nade have smae color
*/

// see https://www.geeksforgeeks.org/m-coloring-problem-backtracking-5/ article




#include<bits/stdc++.h>
using namespace std;

// function that check the adjecent nodes whethter they are colored with same color or not
bool isSafeToPutcolor(int nodeC,bool graph[101][101],vector<int> colors,int V,int col){
    for(int k=0;k<V;k++){
        if(k!=nodeC && graph[k][nodeC]!=1 && colors[k]!=col) return false;
    }
    return 1;
}


// main function
bool graphColoringUtil(int nodeC,bool graph[101][101],vector<int> colors,int m,int V){

// base case
if(nodeC==V) return true;

// tring for each color
for(int col=1;col<m;col++){
    if(isSafeToPutcolor(nodeC,graph,colors,V,col)){
        colors[nodeC]=col;
        if(graphColoringUtil(nodeC+1,graph,colors,m,V)) return true;
        colors[nodeC]=0;
    }
}
return false;
}
bool graphColoring(bool graph[101][101],int m,int V){
    vector<int> colors(V);
    if(graphColoringUtil(0,graph,colors,m,V)) return true;

    return false;
}
           
int main(){
    bool graph[101][101]={
    };
    // cout<<graphColoring(graph,3,5);
  return 0;
}