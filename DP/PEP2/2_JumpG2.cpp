// Jump game 2 || print all paths with minimum number of jumps

/*
Group : 4 Print Paths and Reverse Engineering
1.Print All paths with minimum numbers of Jumps
2.Print Paths with minimum Path Sum
3.Print All paths with Maximum Gold
4.Print Target Sum Subsets
5.Print Paths of 0-1 Knapsacks
*/

/*
Problem is Divided into two parts :
1. Calculate minimum jumps
2. Print all paths with minimum jumps 

So, for calculating minimum jumps traverse back from arr as smallest problem is at last position and 
iterate over the inner loop for jumps and find minimum jump from that loop
and that min jump count and curr jump will gives the total jumps from curr position


And then Now Use BFS for geting min paths
*/
 
 
#include<bits/stdc++.h>
using namespace std;

int minimumJumps(vector<int> arr,int n){

    vector<int> dp(n,INT_MAX);
    dp[n-1]=0;

    for(int i=n-2;i>=0;i--){
        int stp = arr[i];

        int mi = INT_MAX;
        for(int j=1;j<=stp && i+j <n;j++){
            mi = min(mi, dp[i+j]);
        }

        if(mi!=INT_MAX) dp[i] = mi+1;
    } 
    return dp[0] != INT_MAX ? dp[0] : -1;
}






// code for print paths
class paths{
    public:
    int i; //index
    int s; //kitane size ki jump
    int j; //jumps
    string psf;

    paths(int i,int s,int j,string psf){
        this->i = i;
        this->s = s;
        this->j = j;
        this->psf = psf;
    }
};
    void PrintminimumJumpsPaths(vector<int> arr,int n){

        vector<int> dp(n,INT_MAX);
        dp[n-1]=0;

        for(int i=n-2;i>=0;i--){
            int stp = arr[i];

            int mi = INT_MAX;
            for(int j=1;j<=stp && i+j <n;j++){
                mi = min(mi, dp[i+j]);
            }

            if(mi!=INT_MAX) dp[i] = mi+1;
        } 

        if(dp[0] == INT_MAX) return;

        // BFS Start here
        // creating queue and pushing first element to queue
        queue<paths> q;
        q.push(paths(0,arr[0],dp[0],""));

        while(!q.empty()){
            // get front in rem and pop it
            paths rem = q.front();
            q.pop();

            // if jumps count go to 0 that mens we reach at end then print the path
            if(rem.j == 0){
                cout<<rem.psf<<endl;
            }
            else{
                // else check for all jumps from which we have taken rem.j - 1th jump and push them to queue
                for(int j = 1; j <= rem.s && rem.i+j < n ; j++){
                    // below step is for push all the dp elements which contains curr - 1 jumps
                    if(rem.j-1 == dp[rem.i+j]){
                        q.push(paths(rem.i+j,arr[rem.i+j],dp[rem.i+j], rem.psf + to_string(rem.i+j)+" -> "));
                    }
                }
            }
        }

        }

           
int main(){
      vector<int> arr = {1,1,1,1,1};
    //   cout<<minimumJumps(arr,5);
      PrintminimumJumpsPaths(arr,5);
  return 0;
}