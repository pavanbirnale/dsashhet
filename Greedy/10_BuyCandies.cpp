// Find the minimum and maximum amount to buy all N candies
// Greedy 
// #selfSolved

#include<bits/stdc++.h>
using namespace std;


vector<int> minANDmaxMoney(int candies[],int n,int k){
    
    sort(candies,candies+n);
    int minMoney=candies[0];
    int maxMoney=candies[n-1];

    int i=1,j=n-k-1;
    while(i<=j){
        minMoney+=candies[i];
        i++;
        j-=k;
    }
    i=0;
    j=n-2;
    while(i<=j){
        maxMoney+=candies[j];
        j--;
        i+=k;
    }
    return {minMoney,maxMoney};
}

int main(){
    int candies[]={1,2,3,4,5,6,7,8,9,10};
vector<int> ans=minANDmaxMoney(candies,10,1);
cout<<ans[0]<<" "<<ans[1];
  return 0;
}