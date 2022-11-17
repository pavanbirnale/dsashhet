// Minimum Swaps for Bracket Balancing
// https://practice.geeksforgeeks.org/problems/minimum-swaps-for-bracket-balancing2704/1#
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M =1e9+7;
           


// TC : o(n);
// SC : o(n);
  int minimumNumberOfSwaps(string S){
         vector<char> v;
         int count = 0;
         int idx=0;
         int ans=0;
         for(int i=0;i<S.length();i++){
             if(S[i]=='['){
                 v.push_back(i);
             }}
        for(int i=0;i<S.length();i++){
             if(S[i]=='['){
                 count++;
                 idx++;
             }
             else{
                 count--;
                 if(count<0){
                 ans+=v[idx]-i;
                 swap(S[v[idx]],S[i]);
                 count=1;
                 idx++;
             }}
         }
         return ans;
    }

int main(){
          
  return 0;
}