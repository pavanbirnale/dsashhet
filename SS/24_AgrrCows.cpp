#include<bits/stdc++.h>
using namespace std;
long long cows;
long long n;
const int N=1e6+10;
long long arr[N];

bool canCowsPlaces(int mindist){
    int last_pos=-1;
    int cows_temp=cows;
    for(int i=0;i<n;i++){
        if(arr[i]-last_pos>=mindist || last_pos==-1){
            cows_temp--;
            last_pos=arr[i];
        }
        if(cows_temp==0) break;
    }
    return cows_temp==0;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>cows;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        // TTTTTTTTTTTFFFFFFFFFFFFF 
        int lo=0;
        int hi=1e9;

        while(hi-lo>1){
            int mid=(lo+hi)/2;

            if(canCowsPlaces(mid)){
                lo=mid;
            }
            else{
                hi=mid-1;
            }
        }

        if(canCowsPlaces(hi))cout<<hi<<endl;
        else cout<<lo<<endl;
    }
  return 0;
}