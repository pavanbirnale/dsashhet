// 4. Best Time to Buy and Sell Stocks with Cooldown
// https://www.youtube.com/watch?v=GY0O57llkKQ&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=33

/*
In this problem we have to buy and sell stocks with at least one day of cool down
Approach :
so, we take here three states bought state,sold state and cooldown state
we can only buy new stock with cooldown only
we can sold stocks from bought stocks
and In cooldown stocks are come from prev sold state
*/
// try to visualize

 
#include<bits/stdc++.h>
using namespace std;
           
int buyAndSellStock4(vector<int> prices,int n){

    int obsp = - prices[0];
    int ossp = 0;
    int ocsp = 0;

    for(int i=1;i<n;i++){
        int nbsp = 0;
        int nssp = 0;
        int ncsp = 0;

        // for bought state 
        // this conditions are very importants
        if(ocsp - prices[i] > obsp){
            nbsp = ocsp - prices[i];
        }
        else{
            nbsp = obsp;
        }

        // for sold state
        if(prices[i] + obsp > ossp){
            nssp = prices[i] + obsp;
        }
        else{
            nssp = ossp;
        }

        // for cooled state profit
        if(ossp>ocsp){
            ncsp = ossp;
        }
        else{
            ncsp = ocsp;
        }

        obsp = nbsp;
        ossp = nssp;
        ocsp = ncsp;
    }
    return ossp;
}
           
int main(){
      vector<int> prices = {10,15,17,20,16,18,22,20,22,20,23,25};
      cout<<buyAndSellStock4(prices,12);
  return 0;
}