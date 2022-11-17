// Count possible ways to construct buildings 
// NISBOGFG    =>> https://practice.geeksforgeeks.org/problems/count-possible-ways-to-construct-buildings5007/1#

// similar like count strings only difference is that the building are at both side of road
// so at last return square of ans;

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M =1e9+7;

int TotalWays(int N)
{
    long long int obc = 1;
    long long int osc = 1;
    N--;
    while(N--){
        long long int nbc = osc;
        long long int nsc = (obc+osc)%M;
        
        obc = nbc;
        osc = nsc;
    }
    long long int ans = (obc+osc)%M;
    return (ans*ans)%M;
}

int main(){
    cout<<TotalWays(3);
  return 0;
}