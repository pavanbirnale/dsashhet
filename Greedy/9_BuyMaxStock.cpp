// Buy Maximum Stocks if i stocks can be bought on i-th day

/*
Greedy Article
here what we have to do is that bougnt maximum stocks if i stock can bought on ith day 
and we have a amout k we can buy stacks by using this price
so wht we do is we bought stocks we less price in more quentity then our overall stctocks count incresse
so we sort ithe vectorin incressesing order of price in that wevtor we also have day count
in next for loop if stcok price and days product is less than k then we bought all the stocks 
if not thn we only bught what stock is we can get by division
regularly update k

*/
#include<bits/stdc++.h>
using namespace std;

int maxStocks(int arr[],int n,int k){
    vector<pair<int,int>> stocks;
    for(int i=0;i<n;i++){
        stocks.push_back(make_pair(arr[i],i+1));
    }
    sort(stocks.begin(),stocks.end());
    int stocksCount=0;
    for(int i=0;i<n;i++){
        // dairch buying of all stocks on i th day
        if(stocks[i].first*stocks[i].second<=k){
            stocksCount+=stocks[i].second;
            k-=stocks[i].first*stocks[i].second;
        }
        else{
            // these is for is we cant buy all the stocks then we can buy k/stcokprice definelty
            // andupdate k 
             stocksCount+=(k/stocks[i].first);
              k-=stocks[i].first*(k/stocks[i].first);
        }
    }
    return stocksCount;
}
           
int main(){
    int arr[] ={ 7, 10, 4 };
    cout<<maxStocks(arr,3,100);
  return 0;
}