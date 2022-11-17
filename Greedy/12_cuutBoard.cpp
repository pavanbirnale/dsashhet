//12 . Minimum Cost to cut a board into squares
// 29. CHOCOLA –Chocolate

#include<bits/stdc++.h>
using namespace std;

           
int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        n=n-1;
        m=m-1;
        int row[m];
        int col[n];
        for(int i=0;i<m;i++){
            cin>>row[i];
        }
        for(int i=0;i<n;i++){
            cin>>col[i];
        }

        sort(row,row+m,greater<int>());
        sort(col,col+n,greater<int>());

        int horCount=1;
        int verCount=1;

        int i=0;
        int j=0;
        int ans=0;
    
        while(i<m && j<n){
            if(row[i]>col[j]){
                ans+=row[i]*verCount;
                horCount++;
                i++;
            }
            else{
                ans+=col[j]*horCount;
                verCount++;
                j++;
            }
        }

        while(i<m){
            ans+=row[i]*verCount;
            i++;
        }
        while(j<n){
            ans+=col[j]*horCount;
            j++;
        }
        cout<<ans<<endl;
    }
  return 0;
}
