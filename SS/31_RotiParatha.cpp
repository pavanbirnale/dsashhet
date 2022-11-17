// ROTI-Prata SPOJ

#include<bits/stdc++.h>
using namespace std;

bool canCooked(int rank[],int mid,int reqPar,int n){
    int time=0;
    int currPar=0;
    for(int i=0;i<n;i++){
        time=rank[i];
        int nextPar=2;
        while(time<=mid){
            currPar++;
            time+=rank[i]*nextPar;
            nextPar++;
        }
        if(currPar>=reqPar) return 1;
    }
    return 0;
}

           
int main(){
    int t;
    cin>>t;
    while(t--){
        int reqPar,numOfCooks;
        cin>>reqPar;
        cin>>numOfCooks;
        int rank[numOfCooks];
        for(int i=0;i<numOfCooks;i++){
            cin>>rank[i];
        }

        int lo=0;
        int hi=10e8;
        int ans=-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(canCooked(rank,mid,reqPar,numOfCooks)){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        cout<<"  "<<ans<<endl;
    }
  return 0;
}