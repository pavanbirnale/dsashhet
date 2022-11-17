// Largest rectangular Area in Histogram
// https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1
#include<bits/stdc++.h>
using namespace std;

long long max_histogram(long long hist[],int n){
    long long ma=INT_MIN;
    long long i=0;
    stack<long long> st;
    while(i<n){
        if(st.empty() or hist[st.top()] <=hist[i]){
            st.push(i);
            i++;
        }
        else{
            long long tp=st.top();
            st.pop();
            long long ans = hist[tp] * (st.empty() ? i : i-st.top()-1 ) ;
            ma=max(ma,ans);
        }
    }
    while(!st.empty()){
        long long tp=st.top();
        st.pop();
        long long ans = hist[tp] * (st.empty() ? i : i-st.top()-1 ) ;
        ma=max(ma,ans);
    }
    return ma;
}
           
int main(){
          
  return 0;
}