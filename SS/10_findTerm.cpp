// find a pair with a given difference
// Find Pair Given Difference

/*
Algo: we have given arr and its size along with and number and we have to
 find the terms in an array whose differnce is equal to that num
---------------these problem is under the searching sorting concept so we find it by two pointer approch
also another approch is present by using hash map
*/
#include<bits/stdc++.h>
using namespace std;

// TC: O(N) SC: O(N)
bool findPair(int *arr, int size,int n){
        unordered_map<int,int> mp;
    for(int i=0;i<size;i++){
        mp[arr[i]]++;
    }
    for(int i=0;i<size;i++){
        int numToFind=arr[i]-n;
        if(mp.find(numToFind)!=mp.end()) return true;
    }
    return false;
}

// TC: O(N) SC: O(1)
bool findPair(int *arr, int size,int n){
        sort(arr,arr+size);
    
    int lo=0;
    int hi=1;
    
    while(hi<size){
        int dif=abs(arr[hi]-arr[lo]);
        if(dif==n) return true;
        else if(dif<n)hi++;
        else lo++;
        
        if(lo==hi) hi++;
        
    }
    return false;
}
           
int main(){
          
  return 0;
}