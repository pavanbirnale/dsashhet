 
 
#include<bits/stdc++.h>
using namespace std;

class Path{
    public : 
    int i;
    int j;
    string psf;

    Path(int i,int j,string psf){
        this->i = i;
        this->j = j;
        this->psf = psf;
    }

};

void PrintLCS(string s1,string s2,int a,int b){
    vector<vector<int>> dp(a+1,vector<int>(b+1,-1));

    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            if(i==0 || j==0) dp[i][j] = 0;
            else if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else{
                dp[i][j] = max(dp[i-1][j] ,dp[i][j-1]);
            }
        }
        
    }
    cout<<dp[a][b]<<endl;

    for(auto row : dp){
        for(auto i : row){
            cout<<i<<" ";
        }
        cout<<endl;
    }
        queue<Path> q;
        q.push(Path(a,b,""));
        while(!q.empty()){
            Path rem = q.front();
            q.pop();

            if(rem.i==0 || rem.j==0){
                cout<<rem.psf<<endl;
                return;
            }
            else{
                if(s1[rem.i-1]==s2[rem.j-1]){
                    q.push(Path(rem.i-1,rem.j-1,s2[rem.j-1]+rem.psf));
                }
                else if(dp[rem.i][rem.j-1]>=dp[rem.i-1][rem.j]){
                    q.push(Path(rem.i,rem.j-1,rem.psf));
                }
                else {
                    q.push(Path(rem.i-1,rem.j,rem.psf));
                }
            }
        }
}
           
int main(){
      PrintLCS("dad","add",3,3);
  return 0;
}