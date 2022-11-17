// Find shortest safe route in a path with landmines

// very very favorite problem
// article 
// Also 



#include<bits/stdc++.h>
using namespace std;

// global row and col size and in proble passes rows and cols value also used
#define R 12
#define C 10

// function return whether the given celll is safe or not 
// basicaaly it checks wheather its is sorrouded of landmine or allredy visited
bool isSafe(vector<vector<int>> mat,vector<vector<bool>>visited,int i,int j){
    if(mat[i][j]==0 || visited[i][j]){
        return false;
    }
    return true;
}

// function for checking boundry condition of matrix 
bool isValid(int r,int c){
    if(r<0 || c<0 || r>=R || c>=C) {
        return false;
    }
    return true;
}

// function that makes landmines adjecents cell to unsafe
void markUnsafeCells(vector<vector<int>> &mat,int rows,int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){

            // if landmine found
            if(mat[i][j]==0){

                // top cell
                if(isValid(i-1,j)){
                    mat[i-1][j]=-1;
                }
                // left cell
                if(isValid(i,j-1)){
                    mat[i][j-1]=-1;
                }
                // right cell
                if(isValid(i,j+1)){
                    mat[i][j+1]=-1;
                }
                // bottom cell
                if(isValid(i+1,j)){
                    mat[i+1][j]=-1;
                }
            }
        }
    }


    // very very very important 
    // firstly in above loops we set value to -1 because easy chaking
    //  and if we set nest cell to 0 then it will also cheacked in next interation soo
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(mat[i][j]==-1) mat[i][j] = 0;
        }
    }
}

// main function
void findShortSafePathUtil(vector<vector<int>> mat,vector<vector<bool>> visited,int &minDist,int i,int j,int newDist){
    // if we reack to last column then return 
    if(j == C-1){
        minDist = min(minDist,newDist);
        return;
    }

    // if curr dist is more that minDist then no need to go further becuse we not get min from that
    if(newDist>minDist){
         return;
    }

    // set visited of i,j to true 
    visited[i][j] = true; 

    //set recursive call to all four directions  
    if(isValid(i,j-1) && isSafe(mat,visited,i,j-1)) findShortSafePathUtil(mat,visited,minDist,i,j-1,newDist+1);
    if(isValid(i,j+1) && isSafe(mat,visited,i,j+1)) findShortSafePathUtil(mat,visited,minDist,i,j+1,newDist+1);
    if(isValid(i-1,j) && isSafe(mat,visited,i-1,j)) findShortSafePathUtil(mat,visited,minDist,i-1,j,newDist+1);
    if(isValid(i+1,j) && isSafe(mat,visited,i+1,j)) findShortSafePathUtil(mat,visited,minDist,i+1,j,newDist+1);

    // whule backtraking reset visited of i j
    visited[i][j] = false;
}

void findShortSafePath(vector<vector<int>> mat){
    int r = mat.size();
    int c = mat[0].size();

   // call to makeunsafe function
    markUnsafeCells(mat,r,c);

    vector<vector<bool>> visited(r,vector<bool>(c,false));

    int minDist = INT_MAX;

    // try for each row whether we can rech to last column
    for(int i=0;i<r;i++){
        // if it is safe the call only
        if(mat[i][0]==1){
            findShortSafePathUtil(mat,visited,minDist,i,0,0);
        }

        // Think deeply for below line
        if(minDist==c-1) break;
        // our minimum distace will not less than c-1 as we have to move from 0 to c-1
    }

    if(minDist!=INT_MAX){
        cout<<minDist<<" is minimum distance";
    }
    else{
        cout<<"Distination can Not be reachable in given matrix";
    }
}

int main(){
    vector<vector<int>> mat = {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
    };

    findShortSafePath(mat);

    return 0 ;
}