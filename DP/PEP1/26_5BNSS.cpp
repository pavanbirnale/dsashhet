// 5 Best Time to Buy and sell stock at most Two Transations allowed
// https://www.youtube.com/watch?v=wuzTpONbd-0&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=34

/*
In this problem what we have to do is to find maximum profit by buying and seeing stockas at most twice

so what we do is store the maximum profit if sold today till now in dp1 array and
also store maximum profit is bought today and sold in future in dp2 array

and at last the point any point where maximum sum of dp1[i] and dp2[i] will answer


// main point is that both the transation will never overlap with each other by the the following approach
*/

 
 
#include<bits/stdc++.h>
using namespace std;
           
int  buyAndSellStock5(vector<int> prices,int n){

    // forward traversal similar like single transaction allowed only store in dp 
    int leastTillNow = prices[0];
    vector<int> dp1(n);

    for(int i=1;i<n;i++){

        if(leastTillNow > prices[i]) leastTillNow=prices[i];
        int currProfitIfSoldToday = prices[i] - leastTillNow;
        dp1[i] = max(dp1[i-1] , currProfitIfSoldToday);

    }

    // backword traversal ( reverse single transaction allowed)
    int mostInFuture = prices[n-1];
    vector<int> dp2(n);

    for(int i=n-2;i>=0;i--){
        if(mostInFuture<prices[i]) mostInFuture = prices[i];
        int currProfitIfBoughtToday = mostInFuture - prices[i];

        dp2[i] = max(dp2[i+1],currProfitIfBoughtToday);
    }

    int maxProfit = 0;
    for(int i=0;i<n;i++){
        maxProfit = max(maxProfit,dp1[i]+dp2[i]);
    }
    return maxProfit;
}
           
int main(){
    vector<int> prices = {30,40,43,50,45,20,26,40,80,50,30,15,10,20,40,45,71,50,55};
      cout<<buyAndSellStock5(prices,prices.size());
  return 0;
}