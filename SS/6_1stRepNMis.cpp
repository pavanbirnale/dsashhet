// Find the repeating and the missing
// Find Missing And Repeating

/*
Algo:
 here we store frq of elements in the map if the elem thas freq greeter than 1 
 and the elemt has freq is zero are the our ansers
*/
#include<bits/stdc++.h>
using namespace std;

int *FindRepetativeNmissing(int* arr,int n){
    int *ans = new int[2];
    unordered_map<int,int> frq;

    for(int i=0;i<n;i++){
        frq[arr[i]]++;
    }
    // for duplicate
    for(auto i:frq){
        if(i.second>1) ans[0]=i.first;
    }
    // for missing
    for(int i=0;i<n;i++){
        if(frq[i]==0) ans[1]=i;
    }
    return ans;
}
           
int main(){
          
  return 0;
}