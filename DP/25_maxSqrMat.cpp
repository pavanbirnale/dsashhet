// Maximum size square sub-matrix with all 1s
// Largest Square Submatrix of all 1's | Dynamic Programming

/*z
In this problem what we have to do is to find maximum size square matrix it 1s only
for eg:
        1 1 1 1 1
        1 1 1 1 1      here ans is 5
        1 1 1 1 1
        1 1 1 1 1


        1 0 1 0
        0 1 1 1       here ans is 3
        1 1 1 1
        0 1 1 1

Algorithm : 
1. What :  as smallest problem is at dp[n-1][m-1] we have to use bottom up dp to calculate ans
2. meaning :  at every dp[i][j] mening is how much size square matrix we can form by taking this possition as upper left corner of matrix
3. direction : for every 0 value of matrix we cant form the sq mat by considering this position as upper left corner
so put that to zero in dp and put last row and last column as it in dp

then for every cell from dp[n-2][m-2] to 0 check for min to its right , bottom, diagonally and add 1 to it
as every min say that we can form only min+1 size sq mat by considering this dp[i][j] pos and as the cell which contains to min to from that 
size only that can also contains to curr dp[i][j] so we can only from min+1 size mat as ans

and at last traverse the dp and find max that will be the ans

*/
 

// on gfg slits diffent code is written by you
#include<bits/stdc++.h>
using namespace std;
           
int largestSqrMatrix(vector<vector<int>> mat ,int n,int m){

    vector<vector<int>>  dp(n,vector<int>(m,0));

    // base case for last row and last col
    for(int i=0;i<n;i++){
        dp[i][m-1] = mat[i][m-1];
    }
    for(int i=0;i<m;i++){
        dp[n-1][i] = mat[n-1][i];
    }

    int ma = 0;
    for(int i = n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            // if curr is zero then we cant form square mat
           if(mat[i][j]!=0){
                dp[i][j] = min({dp[i+1][j+1],dp[i+1][j],dp[i][j+1]})+1;}
                ma=max(ma,dp[i][j]);
        }
    }
    return ma;
}
           
int main(){
    // 5 6
    vector<vector<int>> mat = {
        {0, 1 ,0 ,1, 0},
        { 1 ,1 ,0, 1, 0},
        { 1, 0, 0, 1, 1},
        { 1, 1, 1, 0, 0},
        { 1, 1 ,1 ,0, 1},
        { 1, 1, 1, 1, 1}
    };
      cout<<largestSqrMatrix(mat,6,5)<<endl;
  return 0;
}