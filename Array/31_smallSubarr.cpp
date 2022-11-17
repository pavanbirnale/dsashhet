// Smallest Subarray with sum greater than a given value
// https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1#
/*
Approch: Two pointer:
// gfg access denied
here we increse j and move forword untill sum> x if these condtion get reached then 
start shinking the window by incresing i and simulteniouly calculate min size also
*/

#include<bits/stdc++.h>
using namespace std;

int minSize(vector<int> vec, int x){
    int n=vec.size();
    int i=0;
    int j=0;
    int mi=INT_MAX;
    int s=0;
    while(i<=j and j<n){
        // increse window size
        while(s<=x and j<n){
            s+=vec[j];
            j++;
        }
        // shink window
        while(s>x and j<n){
            mi=min(mi,j-1);
            s-=vec[i];
            i++;
        }
    }
        return mi;
}
           
int main(){
    vector<int> v={ 1, 11, 100, 1, 0, 200, 3, 2, 1, 250 };
    cout<<minSize(v,280);
  return 0;
}