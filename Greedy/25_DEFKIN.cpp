// DEFKIN -Defense of a Kingdom
//  it is an spoj proplem 
// https://www.spoj.com/problems/DEFKIN/
// https://www.youtube.com/watch?v=fk1yIirivEo&list=PLDdcY4olLQk3cAxZPJXMbxqrM3PlNkmO8&index=15
/*
here what we have to find is find the maximum size undefendable reactangle 

so maximum size reactangle is product of max diffreance of prev and next elemnt on both x and y axis
*/

#include<bits/stdc++.h>
using namespace std;

           
int main(){
    int t;
    cin>>t;
    while(t--){
        int w,h,n;
        cin>>w>>h>>n;
        int x[n+2];
        int y[n+2];
        x[0]=0;
        y[0]=0;
        for(int i=1;i<n+1;i++){
            cin>>x[i];
            cin>>y[i];
        }
        x[n+1]=w+1;
        y[n+1]=h+1;
// 0 3 8 11 16
        sort(x,x+n+2);
        sort(y,y+n+2);

        int mx=0;
        int my=0;

        for(int i=0;i<n+1;i++){
            mx=max(mx,x[i+1]-x[i]-1);
            my=max(my,y[i+1]-y[i]-1);
        }
        cout<<mx*my<<endl;
    }
  return 0;
}