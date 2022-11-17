// Knights Tour
// backtraking
// pepcoding https://www.pepcoding.com/resources/online-java-foundation/recursion-backtracking/knights-tour-official/ojquestion#
// video https://www.youtube.com/watch?v=SP880DBRJ_8&list=PL-Jc9J83PIiFxaBahjslhBD1LiJAV7nKs&index=53

// in this problem what we have to do is to mive the knight in chess board such that knight 
// have to visit all the cells of chess without voilating the property of knigth to move

#include<bits/stdc++.h>
using namespace std;

//function to display the 2-d array
void display(vector<vector<int>>& chess) {
  for (int i = 0; i < chess.size(); i++) {
    for (int j = 0; j < chess.size(); j++) {
      cout << chess[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void printKnightsTour(vector<vector<int>>& chess, int n, int r, int c, int upcomingMove) {

    // checking for voilet condition
    if(r<0 ||c<0 || r>=chess.size()||c>=chess.size()||chess[r][c]>0){
        return;

        // if knite visit all the cells then 
    }else if(upcomingMove==chess.size()*chess.size()){
        chess[r][c]=upcomingMove;
        display(chess);
        chess[r][c]=0;
        return;
    }
    
    // cheting move count and pass to recurtion
    chess[r][c]=upcomingMove;
    
    // checking all the 8 possible possition 
    printKnightsTour(chess,n,r-2,c-1,upcomingMove+1);
    printKnightsTour(chess,n,r-2,c+1,upcomingMove+1);
    printKnightsTour(chess,n,r+2,c-1,upcomingMove+1);
    printKnightsTour(chess,n,r+2,c+1,upcomingMove+1);
    printKnightsTour(chess,n,r-1,c-2,upcomingMove+1);
    printKnightsTour(chess,n,r-1,c+2,upcomingMove+1);
    printKnightsTour(chess,n,r+1,c-2,upcomingMove+1);
    printKnightsTour(chess,n,r+1,c+2,upcomingMove+1);

    // while backtraking reset the move to zero
    chess[r][c]=0;
}

int main() {
    int r,c,n;
    cin>>n>>r>>c;
    vector<vector<int>> chess(n,vector<int>(n,0));
printKnightsTour(chess,n,r,c,1);
}