// Count pairs with given sum
// https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1#
// Two sum : https://leetcode.com/problems/two-sum/

// like two sum 

// Notes Written in HackWithInfyi Revision : 06-03-2022 
/*
Three approaches :
1. Two for loops              O(N2);
2. Sorting and Two pointer    O(NlogN)
3. hash map                   O(N)
*/
#include<bits/stdc++.h>
using namespace std;

int getPairCount(vector<int> vec,int k){
    int c=0;
    unordered_map<int,int> mp;
    for(int i=0;i<vec.size();i++){
        int req=k-vec[i];
        if(mp.find(req)!=mp.end()){
            // if element is present multiple so add mp[req] rather than c++ only
            c+=mp[req];
        }
        mp[vec[i]]++;
    }
    return c;
}
int main(){
    vector<int> vec={1, 5, 7, 1, 1};
       cout<<getPairCount(vec,6);   
  return 0;
}