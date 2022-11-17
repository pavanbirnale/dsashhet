// Print all paths with Maximum Gold || Goldmine Paths

/*
Group : 4 Print Paths and Reverse Engineering
1.Print All paths with minimum numbers of Jumps
2.Print Paths with minimum Path Sum
3.Print All paths with Maximum Gold
4.Print Target Sum Subsets
5.Print Paths of 0-1 Knapsacks
*/


 
 
#include<bits/stdc++.h>
using namespace std;

class paths{
    public:
    int i;
    int j;
    string psf;

    paths(int i,int j,string psf){
        this->i = i;
        this->j = j;
        this->psf = psf;
    }
};
void maxGold(int n, int m, vector<vector<int>> M)
     {
        //  edge case for single row
         if(n==1){
             int ans=0;
             for(int i=0;i<m;i++) ans+=M[0][i];
             return;
         }
        //   rest of cases
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int mtn=INT_MIN;
        // traverse from last column
        for(int j=M[0].size()-1;j>=0;j--){
            for(int i=M.size()-1;i>=0;i--){
                // if col is last then user input matrix to set value sin dp
                if(j==M[0].size()-1){
                    dp[i][j]=M[i][j];
                }
                // if 1st row then we cant check up right cell
                else if(i==0){
                    dp[i][j]=max(dp[i][j+1],dp[i+1][j+1])+M[i][j];
                }
                // if row is last then we cant check right down cell
                else if(i==M.size()-1){
                    dp[i][j]=max(dp[i][j+1],dp[i-1][j+1])+M[i][j];
                }
                // for rest of cell check all three directions
                else{
                    dp[i][j]=max({dp[i][j+1],dp[i-1][j+1],dp[i+1][j+1]})+M[i][j];
                }
                mtn=max(mtn,dp[i][j]);
            }
        }
        //  for(auto row : dp){
        //     for(auto i : row){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }
        // create que
        queue<paths> q;
        // push all the position of 10 col to queue
        for(int i=0;i<n;i++){
            if(dp[i][0]==mtn){
                q.push(paths(i,0,to_string(i)+" "));
            }
        }
        // cout<<q.front().i<<endl;
        while(!q.empty()){
            paths rem = q.front();
            q.pop();

            // if we reach at last column then print ans
            if(rem.j==m-1){
                cout<<rem.psf<<endl;
            }
            // for first row
            else if(rem.i==0){
                // calculate max from d2,d3 pos and push that to queue
                int g = max(dp[rem.i][rem.j+1],dp[rem.i+1][rem.j+1]);

                if(g==dp[rem.i][rem.j+1]){
                    q.push(paths(rem.i,rem.j+1,rem.psf+"d2"));
                }
                if(g==dp[rem.i+1][rem.j+1]){
                    q.push(paths(rem.i+1,rem.j+1,rem.psf+"d3"));
                }
            }
            else if(rem.i==n-1){
                 // calculate max from d2,d1 pos and push that to queue
                int g = max(dp[rem.i][rem.j+1],dp[rem.i-1][rem.j+1]);

                if(g==dp[rem.i][rem.j+1]){
                    q.push(paths(rem.i,rem.j+1,rem.psf+"d2"));
                }
                if(g==dp[rem.i-1][rem.j+1]){
                    q.push(paths(rem.i-1,rem.j+1,rem.psf+"d1"));
                }
            }
            else{
                //  // calculate max from d1,d2,d3 pos and push that to queue
                int g = max({dp[rem.i][rem.j+1],dp[rem.i+1][rem.j+1],dp[rem.i-1][rem.j+1]});

                if(g==dp[rem.i][rem.j+1]){
                    q.push(paths(rem.i,rem.j+1,rem.psf+"d2"));
                }
                if(g==dp[rem.i+1][rem.j+1]){
                    q.push(paths(rem.i+1,rem.j+1,rem.psf+"d3"));
                }
                if(g==dp[rem.i-1][rem.j+1]){
                    q.push(paths(rem.i-1,rem.j+1,rem.psf+"d1"));
                }
            }
        }
    }
           
int main(){
    vector<vector<int>> m={{1, 3, 3},
                   {2, 1, 4},
                  {0, 6, 4}};
    maxGold(3,3,m);
  return 0;
}