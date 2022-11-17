// Merge two binary Max heaps 

/*
Algo : 
Approch 1: heap use another heap and push all the element to heap 
           and then at last pop elemnt one by one =and push it into arr

            TC : O(NLogN);
            SC : O(N);

Approch 2: push both the heap into arr and sort that arra nad then return arr
            TC : O(NLogN);
            SC : O(1);

Approch 3: Two Pointer Approch (below emplemented)
            TC : O(N);
            SC :(1)

*/
#include<bits/stdc++.h>
using namespace std;

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
       vector<int> ans;
       
       int i=0,j=0;
       
       while(i<n and j<m){
           if(a[i]>b[j]){
               ans.push_back(a[i++]);
           }
           else{
               ans.push_back(b[j++]);
           }
       }
       while(i<n){
           ans.push_back(a[i++]);
       }
       while(j<m){
           ans.push_back(b[j++]);
       }
       return ans;
    }
           
int main(){
          
  return 0;
}