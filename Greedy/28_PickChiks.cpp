#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M =1e9+7;
           
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
  long long int t,i,j;
  cin>>t;
  for(j=0;j<t;j++){
      long long int N,K,B,T;
      cin>>N>>K>>B>>T;
      long long int pos[N];
      long long int spd[N];
      for(i=0;i<N;i++){
          cin>>pos[i];
      }
      for(i=0;i<N;i++){
          cin>>spd[i];
      }
      long long int swapCount=0,count=0,notpossible=0;
      for(i=N-1;i>=0;i--){
          long long int distanceCanReach=spd[i]*T;
          long long int distanceNeeded=B-pos[i];

          if(distanceCanReach>=distanceNeeded){
              count++;
              swapCount+=notpossible;
          }
          else{
              notpossible++;
          }

          if(count>=K) break;
      }
    if(count>=K)
          cout<<"Case #"<<j+1<<": "<<swapCount<<endl;
 
       else
         cout<<"Case #"<<j+1<<": "<<"IMPOSSIBLE"<<endl;
  }     
  return 0;
}       