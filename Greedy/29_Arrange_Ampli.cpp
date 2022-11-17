// ARRANGE -Arranging Amplifiers

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
          int t;
cin>>t;
while(t--){
    int n,x;
    cin>>n;
    int arr[n];
    int onesCount=0;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x==1) onesCount++;
        arr[i]=x;
    }
    sort(arr,arr+n,greater<int>());

    for(int i=0;i<onesCount;i++){
        cout<<1<<" ";
    }
    if(n-onesCount==2 && arr[0]==3 && arr[1]==2){
        cout<<2<<" "<<3;
    }
    else{
    for(int i=0;i<n-onesCount;i++){
        cout<<arr[i]<<" ";
    }}
    cout<<endl;
}
  return 0;
}