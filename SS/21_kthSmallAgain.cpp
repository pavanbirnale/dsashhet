// Kth smallest number again
// Kth smallest number again
// hacker earth problem
/*
Algo: 
solve problem by deviding it int to three sections:
1). first sort in put pairs array
2).merge the overlaping intervals
3).search in final array
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
           
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<pair<ll,ll>> arr;
        for(int i=0;i<n;i++){
            ll x,y;
            cin>>x>>y;
            arr.push_back({x,y});
        }
        sort(arr.begin(),arr.end());
        
        int idx=0;
        for(int i=1;i<n;i++){
            if(arr[idx].second>=arr[i].first){
                arr[idx].second=max(arr[idx].second,arr[i].second);
            }
            else{
                idx++;
                arr[idx]=arr[i];
            }
        }

        while(q--){
            ll k;
            cin>>k;
            ll ans=-1;
            for(int i=0;i<=idx;i++){
                if((arr[i].second-arr[i].first+1)>=k){
                    ans=arr[i].first+k-1;
                    break;
                }
                else{
                    k-=(arr[i].second-arr[i].first+1);
                }
            }
            cout<<ans<<endl;
        }
    }
  return 0;
}
