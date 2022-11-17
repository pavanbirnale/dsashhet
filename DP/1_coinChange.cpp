// Coin Change Problem
// Coin Change Combinations

// below problems are come in one categary
/*
1. Subset sum || amount sum subset
2. Coin Change combinations
3. Coin Change permutation
4. coin change problem
5. 0-1 knapsack
6. unbounded knapsack
*/

/*

There are four categories of coin change problem 
1. Normal coin change that returns count of number of unique combinations
   which is coin change combinations for coins 2 3 5 amount 7 then combinations are : 2 5 , 2 2 3
2. Coin change Permutation return all the permutation of combinations 
   for coins 2 3 5 amount 7 then permutations are 2 2 3 , 2 3 2 , 3 2 2 , 2 5 , 5 2 but we have to only return count
3. Coin change return  minimum dominations of coins to from amount amount 
   leetcode => https://leetcode.com/problems/coin-change/





in this problem what we have given is that an coins of coin whose supply is infinite 
and we have to find how many way of combination to make change of amount

https://www.youtube.com/watch?v=l_nR5X9VmaI&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=14
so we use 1D dp here : 
*/

#include<bits/stdc++.h>
using namespace std;

// 1. Coin change combinations
int coinChangeCombinations(vector<int> coins,int amount){
    int n =  coins.size();
    // create array of amount+1 elem
    vector<int> dp(amount+1);
    dp[0]=1;
    // iterate over coins array 
    for(int i=0;i<coins.size();i++){
        // put the values of at dp[j] such a that if dp[j-coins[i]] can gives change of coins[i]-j coins
        // if start from such j where coin value is less than amount 
        // in below line j is amount when we do j-coins[i] that means it gives remaining amount we need to get 
        // so we check in prev dp at remaining amount possition 
        for(int j=coins[i];j<dp.size();j++){
            dp[j]+=dp[j-coins[i]];
        }
    }
    //    for(int i=0;i<dp.size();i++) cout<<dp[i]<<" ";
    return dp[amount];
}

// 2.Coin Change Permutation
int coinChangePermute(vector<int> coins,int amount){
    int n = coins.size();

    vector<int> dp(amount+1);
    dp[0]=1;
    // for permutation for every cell we have to check for all possible coins do inner for loop will be of coins
    // and outer for loop will be of amount
    // 
    for(int i = 1;i < amount+1;i++){
        for(int j = 0; j < n ; j++){
            // this below if condition is for if amount i is smaller than coin then we not do any thing
            if(i>=coins[j])
            dp[i]+=dp[i-coins[j]];
        }
    }
    return dp[amount];
}

// 3.minimum counts of coins require to make amount
int coinChangeCOunt(vector<int> coins,int amount){

    vector<int> dp(amount+1,amount+1);
    dp[0]=0;

    for(int i=0;i<coins.size();i++){
        for(int j=0;j<amount+1;j++){
            if(j>=coins[i])
            dp[j]=min(dp[j],dp[j-coins[i]]+1);
    }
}
return dp[amount] > amount ? -1 : dp[amount];
}

int main(){
    vector<int> coins = {2,3,5};
          cout<<coinChangeCombinations(coins,7)<<endl;
          cout<<coinChangePermute(coins,7)<<endl;
          cout<<coinChangeCOunt(coins,7)<<endl;
  return 0;
}