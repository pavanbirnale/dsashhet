// Maximize the sum of arr[i]*i


#include<bits/stdc++.h>
using namespace std;
long long int mod =10e9+7;
int maxprod(int arr[],int n){
    sort(arr,arr+n);
    int ans=0;
    for(int i=0;i<n;i++){
        ans+= (i * arr[i]) % mod;
    }
    return ans;
}
           
int main(){
    int arr[]={5, 3, 2, 4, 1};
    cout<<maxprod(arr,5);
  return 0;
}