// 29_ printing Shortest common Supersequence

// BFS

/*
Code variation : In LCS we only add common char to psf ans
but here we add common chars only once and different chars in both the cases that 
mens add chars from up and left side of dp cell
*/
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
void PrintSCS(string a,string b,int n,int m){

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(a[i-1]==b[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<(m+n)-dp[n][m]<<endl;

    queue<Path> q;
    q.push(Path(n,m,""));
    int x,y;
    string ans;
    while(!q.empty()){
        Path rem = q.front();
        q.pop();

        if(rem.i==0 || rem.j==0){
            ans=rem.psf;
            x=rem.i;
            y=rem.j;
            break;
        }
        else{
            if(a[rem.i-1]==b[rem.j-1]){
                q.push(Path(rem.i-1,rem.j-1,a[rem.i-1]+rem.psf));
            }
            else if(dp[rem.i-1][rem.j]>=dp[rem.i][rem.j-1]){
                q.push(Path(rem.i-1,rem.j,a[rem.i-1]+rem.psf));
            }
            else{
                q.push(Path(rem.i,rem.j-1,b[rem.j-1]+rem.psf));
            }
        }
    }
    x--;
    y--;
    while(x>=0){
        ans=a[x]+ans;
        x--;
    }
    while(y>=0){
        ans=b[y]+ans;
        y--;
    }
    cout<<ans<<endl;
}
// GEHEKLLO
// GEHEKLLO
int main(){
      PrintSCS("HELLO","GEEK",5,4);
  return 0;
}