// Check if it is possible to survive on Island
// https://practice.geeksforgeeks.org/problems/check-if-it-is-possible-to-survive-on-island4922/1

/*
In these problem we have to wheather we can surive on island or not in the above conditions :
1. We have to servive for S days;
2. N maximum food can buy in each day
3. M unit of food require on each day
4.there is only one shop on island and it was close on sunday so we cant buy food on sunday

so our alog is :
first we have to find how much food we req it is = product of numofdays and amount of food req on each day
                                         totalFoodReq = S*M
then find how much days we can buy food that mense subtract sundays count from all days(S)
sundayCount=S/7;
numOfDyasAfterSubTSunday=S-sundayCount;

after that find how many times we have to purchess food

howManyTimePurchess = totalFoodReq / N(Food buy on each day)

to handdle ceil condition

if(totalFoodReq % N != 0) then increment howManyTimePurchess++;

final check if(numOfDyasAfterSubTSunday>=howManyTimePurchess) return howManyTimePurchess;
else return -1;

*/

#include<bits/stdc++.h>
using namespace std;

int minimumDays(int daysToServive ,int foodCanBuy ,int dailyFoodReq){

    int totalFoodReq = daysToServive * dailyFoodReq;
    
    int sundayCount = daysToServive / 7;
    int howManyRemDaysToBuyFood = daysToServive - sundayCount;

    int buyingCount = totalFoodReq / foodCanBuy;

    if(totalFoodReq % foodCanBuy != 0) buyingCount++;

    if(howManyRemDaysToBuyFood>=buyingCount) return buyingCount;
    else return -1;

}
           
int main(){
    int ans =minimumDays(10,20,30);
    if(ans==-1){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES "<<ans<<endl;
    }
  return 0;
}