// EKOSPOJ:
// eko spoj
#include<bits/stdc++.h>
using namespace std;

const int N =1e6+10;
int Trees;
long long Amt;
long long arr[N];

// pridecate function
bool isAmtSufficient(int h){
    long long currAmt=0;
    for(int i=0;i<Trees;i++){
        if(arr[i]>=h)
        currAmt+=(arr[i]-h);
    }
    return Amt<=currAmt;
}

int main(){
    cin>>Trees;
    cin>>Amt;

    for(int i=0;i<Trees;i++){
        cin>>arr[i];
    }
    long long lo=0;
    long long hi=1e9;
    long long mid;

    while(hi-lo>1){
        mid=(lo+hi)/2;
        if(isAmtSufficient(mid)){
            lo=mid;
        }
        else{
            hi=mid-1;
        }
    }
if(isAmtSufficient(hi)){ cout<<hi<<endl;}
else {cout<<lo<<endl;}
  return 0;
}