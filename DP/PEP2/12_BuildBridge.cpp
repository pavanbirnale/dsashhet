// Maximum non overlaping bridges || Build Bridges

// mush watch : https://www.youtube.com/watch?v=o1h3aoeSTOU&list=PL-Jc9J83PIiEZvXCn-c5UIBvfT8dA-8EG&index=12

/*
This problems are come in singal group : 

Group 5 : Longest Incressing subsequence (LIS)
1. Longest Incresing Subsequence
2. Maximum Sum Incresing Subsequence
3. Longest Bitonic Subsequences
4. Maximum non Overlaping bridges
5. Russian Doll Problem
6. Perfect Squares
*/


/*
In this problem we have to calculate the count of maximum number of non overlaping bridges

What ? : sort the pools according to north bank and then do LIS on south bank omax will be the answer
*/

 
 
#include<bits/stdc++.h>
using namespace std;

class Bridge{
    public :
    int n;
    int s;

    Bridge(int n,int s){
        this -> n = n;
        this -> s = s;
    }
};


// sort pool according to north bank
bool comp(Bridge a,Bridge b){
    return a.n < b.n;
}
int maxNonOverlapingBridges(Bridge b[],int n){
     
     vector<int> dp(n);
     sort(b,b+n,comp);

     int omax = 0;
     for(int i=0;i<n;i++){
         int ma=0;
         for(int j=0;j<i;j++){
             if(b[j].s <= b[i].s && dp[j]>ma){
                 ma = dp[j];
             }
         }
         dp[i] = ma+1;
         omax = max(omax,dp[i]);
}
    return omax;

}
        //    8 1 4 3 5 2 6 7 
        //    1 2 3 4 5 6 7 8
int main(){
      Bridge b[] = {{8, 1}, {1, 2}, {4, 3}, {3, 4},{5, 5}, {2, 6}, {6, 7}, {7, 8}};
      cout<<maxNonOverlapingBridges(b,8);
  return 0;
}