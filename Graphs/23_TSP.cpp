// TSP || Traveling Salesman Problem || Np complite 
// Very very very very nice explanation : https://www.youtube.com/watch?v=JE0JE8ce1V0&t=1269s



// There are two approaches to solve this problem
// 1. Dynamic Programing
// 2. Branch And Bound method ------> youtube.com/watch?v=hh-uFQ-MGfw
            

/*
Algorithm : We use Approach of recursion  + bitmasking dp;

Here bit mask of number of city size is use to check weather the city is visited or not

1<<n == 2^n

so if we have three cities then n = 4;
1<<4 == 2^4 i.e 16
and bits of 16 are : 10000;
if we -1 from 16 then it will be 15
and bits of 15 are : 1111 
by this way we get all set bits

after that we take faith of recursive call that is will give us minimum cost to reaching to k to b for reaching us from a to b;
and if we will add curr city cost in it then it may be minimum cost of reaching from a to b

Time complexity : O(n^2 * 2^n);
*/

 
 
#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> dp;

int tsp(int mask,int pos,vector<vector<int>> &cost){
  if(mask==((1<<n)-1)) return cost[pos][0];
  if(dp[mask][pos]!=-1) return dp[mask][pos];

  int ans = INT_MAX;
  for(int city = 0; city<n;city++){
    if(!(mask&(1<<city))){
      // below or operation is to set cityth bit true
      int newAns = cost[pos][city] + tsp(mask|(1<<city),city,cost);
      ans = min(ans,newAns);
    }     
  }
  return dp[mask][pos]=ans;
}
int find(vector<vector<int>> cost){
  n = cost.size();
  // here 11 is for as it is given in gfg constrain
  dp.resize(1<<11,vector<int>(11,-1));
  return tsp(1,0,cost);
}
int main(){
  vector<vector<int>> cost = {{0,111},{112,0}};
  cout<<find(cost);
  return 0;
}