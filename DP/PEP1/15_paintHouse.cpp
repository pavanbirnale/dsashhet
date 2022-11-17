// paint house -1 || Minimize cost of painting N houses such that adjacent houses have different colors
// this problem not of gfg practice
//  also premium of leetcode
// gfg article : https://www.geeksforgeeks.org/minimize-cost-of-painting-n-houses-such-that-adjacent-houses-have-different-colors/
// https://www.youtube.com/watch?v=kh48JLieeW8&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=23
/*
Algos :  this problem is similar like previous maxsum excluding adjacent sum /  Stickler Thief

Approches : 
1. Dp with 2d table;
2. Dp without extra space using input array only => https://medium.com/@SilentFlame/leetcode-paint-house-dynamic-programming-9253c3b5687c













3. Dp using variabes only                  this approach doest exist (goes wrong way)    only two approaches present















*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Approach : 1 SC: O(N);
void paintHouseApproch1(vector<vector<int>> cost , int n){
    vector<vector<int>> t(n,vector<int>(3,0));

    // base case
    t[0] = {cost[0][0],cost[0][1],cost[0][2]};

    for(int i=1;i<n;i++){

        // t[i][k] holds minimum cost if until if we paint curr house with this color 
        t[i][0] = cost[i][0] + min(t[i-1][1],t[i-1][2]);
        t[i][1] = cost[i][1] + min(t[i-1][0],t[i-1][2]);
        t[i][2] = cost[i][2] + min(t[i-1][0],t[i-1][1]);

    }
   cout<<min({t[n-1][0],t[n-1][1],t[n-1][2]})<<endl;
}


// Approach : 2 SC: O(N) by reusing input cost vector;
void paintHouseApproch2(vector<vector<int>> cost,int n){

    for(int i=1;i<n;i++){
        cost[i][0] += min(cost[i-1][1],cost[i-1][2]);
        cost[i][1] += min(cost[i-1][0],cost[i-1][2]);
        cost[i][2] += min(cost[i-1][1],cost[i-1][0]);
    }
    cout<<min({cost[n-1][0],cost[n-1][1],cost[n-1][2]});
}


// Approach : 3 SC : O(1) does  not exist
void paintHouseApproch3(vector<vector<int>> cost,int n){
    
    // int red = cost[0][0];
    // int green = cost[0][1];
    // int blue = cost[0][2];

    // for(int i=1;i<n;i++){

    //     red=min(red,cost[i][0]+min(cost[i-1][1],cost[i-1][2]));
    //     green=min(green,cost[i][1]+min(cost[i-1][2],cost[i-1][0]));
    //     blue=min(blue,cost[i][2]+min(cost[i-1][1],cost[i-1][0]));
    // }
    // cout<<min({red,green,blue})<<endl;
}

int main(){
    vector<vector<int>> cost =  {{14, 2, 11}, {11, 14, 5}, {14, 3, 10}};

    paintHouseApproch1(cost,3);
    paintHouseApproch2(cost,3);
    // paintHouseApproch3(cost,3);
  return 0;
}