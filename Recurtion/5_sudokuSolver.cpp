// Solve the Sudoku
// Sudoku solver
// https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1
// pepcoding
/*
Algo :
1. what we have to do is we have given an n*n grid which contain integers from 1-9 and 0 randomly
so we have to replac ethe 0 with valid intiger number by following three rules of sudoku
a).Every row contains unique 1-n intigers
b).Every column contains unique 1-n ints
c).Every 3*3 subgerid contains unique 1-n ints
*/

#include<bits/stdc++.h>
using namespace std;

// Global variables
bool isSudokuSolved=false;
int N=9;

// method use to print grid
void print(vector<vector<int>> grid){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }
}

// function use to check whether we can fill the ops number in that (x,y) position or not
   bool isValidPos(vector<vector<int>> grid,int x,int y,int ops){

    //    checking in row
        for(int i=0;i<N;i++){
            if(grid[x][i]==ops) return false;
        }

    //    checking in columns
        for(int i=0;i<N;i++){
            if(grid[i][y]==ops) return false;
        }
    

    // checking in grid of 3*3

    // smr smc are the (0,0) th possition of every grid
        int smr = x/3 * 3;
        int smc = y/3 * 3;

    // checking and traversing in each grid
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
            if(grid[i+smr][j+smc]==ops) return false;
            }
        }
        return true;
    }

// main function 
void sodokuSolverUtil(vector<vector<int>> grid,int r,int c){

    // base case 
    // when we reach (9,0) pos then return that mense we successfull reach at end of grid (8,8)
    // by putting numbers then print sudoku and return
    if(r==N){
        isSudokuSolved=true;
        print(grid);
        return;
    }

    //initialize the new row and col to 0 
    int nr=0,nc=0;

    // contion for col when it reach at (r,8)th position then set back c to zero and increment row
    if(c==N-1){
        nc=0;
        nr=r+1;
    }

    // else increment col and row becomes as it is
    else{
        nc=c+1;
        nr=r;
    }


    // if grid[r][c] contains non zero value that mense it  is all ready fill then siply move to next position 
    if(grid[r][c]!=0){
        sodokuSolverUtil(grid,nr,nc);
    }

    // else it contains zero value then try for all values from 1 to 9  
    else{
        for(int ops=1;ops<=9;ops++){

            // here we check is position (r,c) is valid for puting ops or not
            if(isValidPos(grid,r,c,ops)){
                // then put ops to r,c
                grid[r][c]=ops;
                // call the function to next call
                sodokuSolverUtil(grid,nr,nc);

                // while backtraking reset grid value to zero 
                grid[r][c]=0;
            }
        }
    }
}
bool sudokuSolver(vector<vector<int>> grid){
    sodokuSolverUtil(grid,0,0);
    return isSudokuSolved;
}
           
int main(){
  vector<vector<int>> grid={{3,0,6,5,0,8,4,0,0},
{5,2,0,0,0,0,0,0,0},
{0,8,7,0,0,0,0,3,1},
{0,0,3,0,1,0,0,8,0},
{9,0,0,8,6,3,0,0,5},
{0,5,0,0,9,0,6,0,0},
{1,3,0,0,0,0,2,5,0},
{0,0,0,0,0,0,0,7,4},
{0,0,5,2,0,6,3,0,0}};
  if(sudokuSolver(grid)){
      cout<<"sudoku solved";
  }
  else{
      cout<<"sudoku not solved";
  }        
  return 0;
}