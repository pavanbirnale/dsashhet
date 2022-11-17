// Print All Target Sum Subsets || Print Subset with target sum || Subset Sum

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

    Paths(int i ,int j,string psf){
        this->i=i;
        this->j=j;
        this->psf=psf;
    }
};

void isSubsetSum(vector<int> arr,int sum){
    int n=arr.size();
    // create vector of n+1 and sum+1
    vector<vector<bool>> dp(n+1,vector<bool>(sum+1,0));

    for(int i=0;i<dp.size();i++){
    for(int j=0;j<dp[0].size();j++){
        // first cell
        if(i==0 && j== 0) dp[i][j] = true;

        // first row
        else if(i==0) dp[i][j] = false;

        // first column
        else if(j==0) dp[i][j] = true;

        // rest of cell
        else{
            // batting nahi kar raha and previous team can make the j runs then no need to curr i-1
            if(dp[i-1][j]==true){
                dp[i][j] = true;
            }
            else{
                // bating kar raha ( if previous team can not make j runs then we check is it can make j - currPlayerRun then it wold ib true)
                int val = arr[i-1];
                // before that check whether CurrPlayer run are less than run require 
                if(j>=val){
                    if(dp[i-1][j-val]==true) dp[i][j]=true;
                }

            }
        }
    }
}
        // for(auto row : dp){
        //     for(auto i : row){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }
        // if no any subset is present then return
        if(dp[n][sum]!=1) return;


        // BFS
        queue<Paths> q;
        
        // push last cell of dp to queue
        q.push(Paths(n,sum,""));

        // until become queue empty pop one by one item and push its child with true value 
        while(!q.empty()){
            Paths rem = q.front();
            q.pop();

            // if we reach at 1st row or 1st column then we found subset
            if(rem.i==0 || rem.j==0){
                cout<<rem.psf<<endl;
            }
            else{

            // if it does not batted check its val
            bool exc = dp[rem.i-1][rem.j];
            if(exc) q.push(Paths(rem.i-1,rem.j,rem.psf));

            // check whether player can make run are lesser than require runs then only players run can help full
            if(rem.j>=arr[rem.i-1]){
                bool inc = dp[rem.i-1][rem.j-arr[rem.i-1]];
                // if it is true then push to queue
                if(inc){
                    q.push(Paths(rem.i-1,rem.j-arr[rem.i-1],to_string(arr[rem.i-1])+" "+rem.psf));
                }
            }
            }
        }


}
int main(){
    vector<int> arr = {4,2,7,1,3};
    isSubsetSum(arr,10);
  return 0;
}