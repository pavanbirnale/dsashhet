// Print paths with 0-1 knapsack

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
           

class Paths{
    public:
    int i;
    int j;
    string psf;

    Paths(int i,int j,string psf){
        this->i=i;
        this->j=j;
        this->psf=psf;
    }
};
void ZeroOneKnapsack(int W,vector<int> vals,vector<int> wts){
     vector<vector<int>> dp(wts.size()+1,vector<int>(W+1));

     for(int i=1;i<dp.size();i++){
         for(int j=1;j<dp[0].size();j++){
             if(j>=wts[i-1]){
                 int exc = dp[i-1][j];
                 int inc = dp[i-1][j-wts[i-1]] + vals[i-1];
                 dp[i][j] = max(inc,exc);
             }
             else{
                 dp[i][j] = dp[i-1][j];
             }
         }
     }
    //  return dp[dp.size()-1][W];

    // BFS
    queue<Paths> q;
    q.push(Paths(dp.size()-1,W,""));

    while(!q.empty()){
        Paths rem = q.front();
        q.pop();

        if(rem.i==0 || rem.j==0){
            cout<<rem.psf<<endl;
        }
        else{
            // if exc 
            int exc = dp[rem.i-1][rem.j];
            int inc = dp[rem.i-1][rem.j-wts[rem.i-1]] + vals[rem.i-1];

            // pushing nabours to queue
            if(dp[rem.i][rem.j]==inc){
                q.push(Paths(rem.i-1,rem.j-wts[rem.i-1],to_string(wts[rem.i-1])+" "+rem.psf));
            }
            if(dp[rem.i][rem.j]==exc){
                q.push(Paths(rem.i-1,rem.j,rem.psf));
            }
        }
    }

}
           
int main(){
    int W = 10;
    vector<int> weight = {1,3,4,5};
    vector<int> values = {10,40,50,70};
    ZeroOneKnapsack(W,values,weight);
  return 0;
}