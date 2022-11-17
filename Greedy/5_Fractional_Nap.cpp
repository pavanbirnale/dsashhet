// Fractional Knapsack Problem
// Fractional Knapsack 

#include<bits/stdc++.h>
using namespace std;
struct Items{
double weight;
double value;
};
static bool comp(Items a,Items b){
    double t1=(double)a.value/(double)a.weight;
    double t2=(double)b.value/(double)b.weight;
    return t1> t2;
}
double fractinalKnapsack(int W,Items arr[],int n){

sort(arr,arr+n,comp);
double currWeight=0;
double currValue=0;

for(int i=0;i<n;i++){
    if(currWeight+arr[i].weight<=W){
        currWeight+=arr[i].weight;
        currValue+=arr[i].value;
    }
    else{
        currValue+=(double)arr[i].value/(double)arr[i].weight *(W-currWeight);
        break;
    }
}
return currValue;
}
           
int main(){
          
  return 0;
}