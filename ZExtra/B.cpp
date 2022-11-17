 
#include <bits/stdc++.h>
using namespace std;
                     
#define en "\n"
#define ll long long
#define FAST                          \
   ios_base::sync_with_stdio(false); \
   cin.tie(NULL);
  
  
void solve()
{
     int k,n;
     cin>>k>>n;
     vector<int> arr(n);
     for(int i=0;i<n;i++){
         cin>>arr[i];
     }
     sort(arr.begin(),arr.end());
     int sum = 0;
     sum = accumulate(arr.begin(),arr.begin()+k,sum);
     cout<<k<<endl;
}
  
  
int main(){
  
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
FAST;
     
    ll t = 1;
    cin >> t;
    while (t--)
    {
       solve();
    }
     
    return 0;
}