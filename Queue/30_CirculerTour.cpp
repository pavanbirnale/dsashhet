// https://leetcode.com/problems/gas-station/
// https://practice.geeksforgeeks.org/problems/circular-tour/1

// you have given two arrays and you have to find is circuler tour is possible or not
// for that they givs two arrays one is of petrol/gas and anoter is of disatcnce;

// Two Approches
// 1.Brute Force : O(N^2)
// Try from each pp And check weahrwe we will get back at same position or not 

// 2. optimize : O(N);
// here we can strt from start possition and stop we extra fuel get negative the start from i+1 th position and go till end
// finaly check if req fuel+ extra fuel is> 0 or not and return its positionor -1;
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int start=0;
        int n=gas.size();
       int extrafuel=0;
       int reqfuel=0;
       for(int i=0;i<n;i++){
           extrafuel+=(gas[i]-cost[i]);
           if(extrafuel<0){
               reqfuel +=extrafuel;
               start=i+1;
               extrafuel=0;
           }
       }
       return (reqfuel+extrafuel>=0? start:-1);
    }
};
int main(){
          
  return 0;
}