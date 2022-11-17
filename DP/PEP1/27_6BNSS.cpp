// 6.Best Time to Buy and Sell stocks K transaction allowed
// https://www.youtube.com/watch?v=wuzTpONbd-0&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=35
 
 /*
 It is classical Dp problem
 */
  
  
 #include<bits/stdc++.h>
 using namespace std;

 // NOT Optimal TC : O(N^3) we can eliminate third k loop because it is for only for get max 
 int buyAndSellStock6Naive(vector<int> prices,int n,int k){
     
     vector<vector<int>> dp(k+1,vector<int>(n,0));

   // loop for transaction count that is k
     for(int t = 1;t<=k;t++){
        //  loop for transaction day that is for prices array
         for(int td=1 ; td<n;td++){
            
            // set max to prev day transaction that means all the 3 transaction happened on last day only
            int prevDayProfitThatWillConvertToMAx = dp[t][td-1];

            // this loop is for getting that previous max transaction and last transation can happend with td and k
            for(int k = 0;k < td;k++){
                int lastTransation = prices[td] - prices[k];
                int pofT_1Trans = dp[t-1][k];
                prevDayProfitThatWillConvertToMAx=max(prevDayProfitThatWillConvertToMAx,lastTransation+pofT_1Trans);
            }
            dp[t][td] = prevDayProfitThatWillConvertToMAx;
         }
     }
     return dp[k][n-1];
 }







 int buyAndSellStock6(vector<int> prices,int n,int k){
     
     vector<vector<int>> dp(k+1,vector<int>(n,0));

     for(int t = 1;t<=k;t++){
         int max_ = INT_MIN;
         for(int td=1 ; td<n;td++){

             if(dp[t-1][td-1]-prices[td-1] > max_){
                 max_ = dp[t-1][td-1]-prices[td-1];
             }
             dp[t][td] = max(max_+ prices[td],dp[t][td-1]);

         }
     }
     return dp[k][n-1];
 }










            
 int main(){
     vector<int> prices = {30,40,43,50,45,20,26,40,80,50,30,15,10,20,40,45,71,50,55};
       cout<<buyAndSellStock6(prices,prices.size(),2);
   return 0;
 }