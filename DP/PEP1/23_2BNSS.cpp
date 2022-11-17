// 2. Best Time to buy and sell stocks Infinite Number of Transation are allowed
// https://www.youtube.com/watch?v=HWJ9kIPpzXs&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=31

/*
What : In this problem we have to collect max profit by buying and selling stocks aas many time we want
only single condition is that we cant BBSS stocks we only BSBS stocks.

Approach : first of all we initialize buy sell index to 0 and then as next day price is incress then we incress sell date 
as we reach at such pot=int were on next day prices get decreases then we sold the stocks 


// Another varients of this problem is also presents where we have to print position that mens cout<<buy<<" "<<sell
that is prices index days
*/
 
 
#include<bits/stdc++.h>
using namespace std;
           
int buyAndSellStock2(vector<int> prices,int n){
    int buy=0,sell=0,profit=0;
    for(int i=1;i<n;i++){
        // if equal then also incress sell date
        if(prices[i]>=prices[i-1]){
            sell++;
        }
        else{
            profit+=prices[sell]-prices[buy];
            buy=sell=i;
        }
    }
    profit+=prices[sell]-prices[buy];
    return profit;
}
           
int main(){
    vector<int> prices =  {7, 1, 5, 3, 6, 4} ;
    cout<<buyAndSellStock2(prices,6);
  return 0;
}