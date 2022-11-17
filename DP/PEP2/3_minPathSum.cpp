// print All Paths with Minimum path sum || Minimum Cost Paths

/*
Group : 4 Print Paths and Reverse Engineering
1.Print All paths with minimum numbers of Jumps
2.Print Paths with minimum Path Sum
3.Print All paths with Maximum Gold
4.Print Target Sum Subsets
5.Print Paths of 0-1 Knapsacks
*/

/*
There are two types of problem in this 
1. leetcode problem that mens our start point is at 0,0 and destination is at n-1,n-1
2. gfg problem that mens reverse goldmine 

here we have discuss leetcode problem
*/
 
#include<bits/stdc++.h>
using namespace std;
           
int maximumPath(int n, vector<vector<int>> Matrix)
    {
        vector<vector<int>> dp(n,vector<int>(n,0));
        // start from last position that mens n-1,n-1 and traverse towards 0
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){

                // if it is last row then set matrix value as it is
                if(i == n-1 && j== n-1) dp[i][j] = Matrix[i][j];

                else if(i==n-1) dp[i][j] = Matrix[i][j] + dp[i][j+1];
                else if(j==n-1) dp[i][j] = Matrix[i][j] + dp[i+1][j];
                else dp[i][j] = min({dp[i][j+1],dp[i+1][j]})+ Matrix[i][j];
            }
        }
        return dp[0][0];
    }

           











// code for print paths
class paths{
    public:
    int i; //index i
    int j; //index j
    string psf;

    paths(int i,int j,string psf){
        this->i = i;
        this->j = j;
        this->psf = psf;
    }
};
    void PrintMaximumPath(vector<vector<int>> Matrix,int n){

       vector<vector<int>> dp(n,vector<int>(n,0));
        // start from last position that mens n-1,n-1 and traverse towards 0
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){

                // if it is last row then set matrix value as it is
                if(i == n-1 && j== n-1) dp[i][j] = Matrix[i][j];

                else if(i==n-1) dp[i][j] = Matrix[i][j] + dp[i][j+1];
                else if(j==n-1) dp[i][j] = Matrix[i][j] + dp[i+1][j];
                else dp[i][j] = min({dp[i][j+1],dp[i+1][j]})+ Matrix[i][j];
            }
        }
        for(auto row : dp){
            for(auto i : row){
                cout<<i<<" ";
            }
            cout<<endl;
        }

        // BFS Start here
        // creating queue and pushing first element to queue
        queue<paths> q;
        q.push(paths(0,0,""));

        while(!q.empty()){
            // get front in rem and pop it
            paths rem = q.front();
            q.pop();

            // if we reach at destination then print path
            if(rem.i==n-1 && rem.j==n-1){
                cout<<rem.psf<<endl;
            }
            // if we at last row then push next column to queue
            else if(rem.i==n-1){
                 q.push(paths(rem.i,rem.j+1,rem.psf+"H"));
            }
            // if we at last col then push next row to queue
            else if(rem.j==n-1){
                 q.push(paths(rem.i+1,rem.j,rem.psf+"V"));
            }
            // for rest of cell push minimum among the horizontal and vertical
            else{
                if(dp[rem.i][rem.j+1]>dp[rem.i+1][rem.j]){
                    q.push(paths(rem.i+1,rem.j,rem.psf+"V"));
                }
                else if(dp[rem.i][rem.j+1]<dp[rem.i+1][rem.j]){
                    q.push(paths(rem.i,rem.j+1,rem.psf+"H"));
                }
                // if both horizontal and vertical is same then push both
                else{
                    q.push(paths(rem.i+1,rem.j,rem.psf+"V"));
                    q.push(paths(rem.i,rem.j+1,rem.psf+"H"));
                }
            }
        }

        }

int main(){
    vector<vector<int>> Matrix = {{1, 2, 3},
                                  {2, 5, 6},
                                  {3, 6, 9}};
    //   cout<<maximumPath(2,Matrix);
      PrintMaximumPath(Matrix,3);
  return 0;
}
// 