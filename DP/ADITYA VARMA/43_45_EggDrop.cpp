// Egg Droping || Supper Egg Droping

/*
What ? : In this problem we have given tow integers one number of eggs and building floor
and we have to wristy minimize numbers of attems to find threshold floor

threshold floor : the higest floor of bulding from with egg does not breaks
that mens if we move further above floor then egg will breaks from it 

we dont have to calculate this threshold floor we have to count the attempts that are made to calculate threshold floor.
*/

/*
In first look you notied that this problem is based on binary search also

GFG can accept linear solution as there contrains are only 200 200
But Leetcode give TLE as they have conatains 100 10000 so we have to this about Binary search
*/


/*
Algorithm : 
1). Handdle base cases
2). check from 1st floor to last floor either by linearly or binary
3).calcute worst case result + 1
4). calculate min among them
*/

 
 
#include<bits/stdc++.h>
using namespace std;



int dp[201][201];


// 1). GFG Approach liner checkup for all k's 

int EggDropLiner(int e,int f){
    //  if Eggs become 1 then return f;
    if(e==1) return f;

    // if floors become one or zero then return f
    if(f==0 || f==1) return f;

    if(dp[e][f]!=-1) return dp[e][f];

    int mi = INT_MAX;

    int isBreaks,notBreaks;
    for(int k=1;k<=f;k++){

        // checks here sub problem also whether it can present in dp or not
        isBreaks = dp[e-1][k-1]!=-1 ? dp[e-1][k-1] : dp[e-1][k-1] = EggDropLiner(e-1,k-1);
        notBreaks = dp[e][f-k] !=-1 ? dp[e][f-k] : dp[e][f-k] = EggDropLiner(e,f-k);


        // here we use max because we can find the attempts count in worst case 
        int worst = 1 + max(isBreaks,notBreaks);


       //we have to minimise it so we use below code 
        mi = min(mi,worst);
    }
    return dp[e][f]=mi;
}
           







// 2). leetcode approach Binary search

int EggDroping(int e,int f){
    if(e==1) return f;
    if(f==0 ||f==1) return f;

    if(dp[e][f]!=-1) return dp[e][f];

    int mn = INT_MAX;

    int lo = 1;
    int hi = f;
    int isBreaks,notBreaks;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        isBreaks = dp[e-1][mid-1]!=-1 ? dp[e-1][mid-1] : dp[e-1][mid-1] = EggDropLiner(e-1,mid-1);
        notBreaks = dp[e][f-mid] !=-1 ? dp[e][f-mid] : dp[e][f-mid] = EggDropLiner(e,f-mid);

        if(isBreaks > notBreaks){
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
        int temp = 1 + max(isBreaks,notBreaks);
        mn = min(mn,temp);
    }
    return dp[e][f] = mn;
}
int main(){
    memset(dp,-1,sizeof(dp));

    cout<<EggDroping(3,14);
  return 0;
}