// Printing all solutions in N-Queen Problem
// n queens
// 

#include<bits/stdc++.h>
using namespace std;
// globally initialize answer vector
vector<vector<int>> ans={};

// checking previos palced queens possition 
bool isSafePossitionForQueen(vector<vector<int>>chess,int row,int col,int n){
    // checking in up direction
    for(int i=row-1,j=col;i>=0;i--){
        if(chess[i][j]==1){
            return 0;
        }
    }

    // check in left diagonal
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(chess[i][j]==1){
            return 0;
        }
    }

    // check in right diagonal 
    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
        if(chess[i][j]==1){
            return 0;
        }
    }

    // below possitioned not cheched as untill now we only place queens only above from this possition
    return true;
}

// 
void nQueensHelper(vector<vector<int>> &chess,int n, int row,vector<int>prevQueenPos){

    // IF WE SUCCESSFULLY PLACED QUEENS IN N-1TH ROW THEN RETURN IN NTH ROW
    if(row==n){
        ans.push_back(prevQueenPos);
        return;
    }

    // iterate over each col of every row
    for(int col=0;col<n;col++){
        if(isSafePossitionForQueen(chess,row,col,n)){
            // placeing queen at pos chess[row][col]
        chess[row][col]=1;

        // passing this pos to vector
        prevQueenPos[col]=row+1;
        // calling fun to next row 
        nQueensHelper(chess,n,row+1,prevQueenPos);
        // reseting the pos to 0 when call terminate
        chess[row][col]=0;
        }
    }
}

vector<vector<int>> nQueens(int n){
    vector<vector<int>> chess(n,vector<int>(n,0));
    vector<int>prevQueenPos(n,0);
    nQueensHelper(chess,n,0,prevQueenPos);
    sort(ans.begin(),ans.end());
    return ans;
}

void Print(vector<int> pos){
    int n= pos.size();
    vector<string> board(n,string(n,'-'));
    for(int i=0;i<n;i++){
        board[pos[i]-1][i] = 'q';
    }
    for(int i=0;i<n;i++){
        cout<<board[i]<<endl;
    }
    cout<<endl;
}
           
int main(){
    int n=2;
    vector<vector<int>> queens =nQueens(n);
    for(int i=0;i<n;i++){
        // for(int j=0;j<n;j++){
        //     cout<<queens[i][j]<<" ";
        // }
        Print(queens[i]);
        // cout<<"\n";
    }
  return 0;
}