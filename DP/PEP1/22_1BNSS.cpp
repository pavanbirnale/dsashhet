// 1.Best Time to Buy and Sell Stock in single Transaction
// https://www.youtube.com/watch?v=4YjEHmw1MX0&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=30


/*
Dp group : 3
1.Best Time to Buy and Sell stocks in single Transaction
2.Best Time to Buy and Sell stocks in infinite Transaction
3.Best Time to BUy and Sell stocks with Transaction Fee
4.Best Time to Buy and Sell Stocks With Cooldown
5.Best Time to Buy and sell Stocks in At most 2 Transaction
6.Best Time to Buy and sell Stocks in k number of Transaction
*/

/*
what : In this problem what we have to do is to find maximum profit we can calculate by buy and seeling the stock in single Transaction

How (Approach) : 
we can do time travel from each day and go back and get least price until curr day and buy stock of least price day and sold on curr day
that gives profit of that day

Algorithm : 
initialize a variable least first.
iterate over prices array and check for lest if curr price is least than prev least
then for curr profit it is todays price - least
and at last in loop check of max profit untill now
and return maxprofit
*/
 
 
#include<bits/stdc++.h>
using namespace std;
           
int buyAndSellStock(vector<int> prices,int n){
     int least = INT_MAX;
     int maxProfit = INT_MIN;
     int currProfit = 0;

     for(int i=0;i<n;i++){
      //  step 1 : Maintain least
       if(prices[i]<least){
         least = prices[i];
       }
      //  step 2 : Calculate Profit
       currProfit = prices[i]-least;
       
      //  Step 3 : Maintain max Profit
       if(maxProfit<currProfit){
         maxProfit = currProfit;
       }
     }

     return maxProfit;
}
           
int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};
      cout<<buyAndSellStock(prices,6);
  return 0;
}
