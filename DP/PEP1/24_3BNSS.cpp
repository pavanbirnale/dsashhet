// 3.  Best Time to Buy and sell Stocks with Transaction fees
// https://www.youtube.com/watch?v=pTQB9wbIpfU&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=32

/*
What we have to do is calculate maximum profit by buying and selling stocks with transaction fees;

so what we do is we define two states bought state and sold state in bought state we have done any number of transaction but 
currently we are in bought state ex. b1s1b2 ,b1s2b5
and in sold state we are in b1s1,b2s5 state in this state we have to payfess also 

Approach :  we can only sell on old bought state and from old sold state we can buy new stocks


// try visualize things it will more clear understanding 
*/
 
 
#include<bits/stdc++.h>
using namespace std;
           
int buyAndSellStock3(vector<int> prices,int n,int fees){
    // friest price always -ve first array element
    int obsp = - prices[0];
    int ossp = 0;

    for(int i=1;i<n;i++){
        int nbsp = 0;
        int nssp = 0;

        // bought state 
        // important line ossp-prices[i]
        if(obsp < ossp-prices[i]){
            nbsp = ossp-prices[i];
        }
        else{
            nbsp = obsp;
        }

        // sold state
        // this also important
        if(prices[i] + obsp - fees > ossp){
            nssp = prices[i] + obsp - fees;
        }
        else{
            nssp = ossp;
        }

        // very very important step;
        obsp = nbsp;
        ossp = nssp;

    }
    return ossp;
}
           
int main(){
    vector<int> prices = {10,15,17,20,16,18,22,20,22,20,23,25};
      cout<<buyAndSellStock3(prices,12,3);
  return 0;
}

