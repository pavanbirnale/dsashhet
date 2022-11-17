// Bishu and Soldiers
// hacker earth
#include<bits/stdc++.h>
using namespace std;

           
int main(){
    int n,s;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>s;
        arr[i]=s;
    }
    int q,p,sum,count;
    cin>>q;
    while(q--){
        sum=0;count=0;
        cin>>p;
        for(int i=0;i<n;i++){
            if(arr[i]<=p){
                count++;
                sum+=arr[i];
            }
        }
        cout<<count<<" "<<sum<<"\n";
    }
  return 0;
}