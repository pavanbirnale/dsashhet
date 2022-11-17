// DIEHARD - DIE HARD
// https://www.spoj.com/problems/DIEHARD/
/*
The game is simple. You initially have ‘H’ amount of health and ‘A’ amount of armor. At any instant you can live in any of the three places - fire, water and air. After every unit time, you have to change your place of living. For example if you are currently living at fire, you can either step into water or air.

If you step into air, your health increases by 3 and your armor increases by 2
If you step into water, your health decreases by 5 and your armor decreases by 10
If you step into fire, your health decreases by 20 and your armor increases by 5
If your health or armor becomes <=0, you will die instantly
Find the maximum time you can survive.
*/
// find maximum time to which you can srvive

#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int solve(int h,int a,int i){
    // if any health or armer get 0 then you have died
    if(h<=0 || a<=0){
        return 0;
    }
    if(dp[h][a]!=-1){
        return dp[h][a];
    }

    int x,y,z;
    x=y=z=0;
    // if previusly in water then move to air or  fire accordingly that
    if(i!=1) x=1+solve(h+3,a+2,1);
    if(i!=2) y=1+solve(h-5,a-10,2);
    if(i!=3) z=1+solve(h-20,a+5,3);
    return dp[h][a]=max({x,y,z});
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int health,armor;
        cin>>health>>armor;
        memset(dp,-1,sizeof(dp));
        cout<<max({solve(health+3,armor+2,1),solve(health-5,armor-10,2),solve(health-20,armor+5,3)})<<endl;
    }
  return 0;
}