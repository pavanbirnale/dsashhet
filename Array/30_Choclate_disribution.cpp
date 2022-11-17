// https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
// Article: https://www.geeksforgeeks.org/chocolate-distribution-problem/
// https://www.youtube.com/watch?v=T_2CATt_XyQ&list=PLDdcY4olLQk3zG-972eMoDJHLIz3FiGA6&index=20
// Chocolate Distribution Problem
/*
Approch 1: subset approch 
    First Find all the subset of arr whose size is num of student
    then find min and max in each subset and return minimun of then
Approch 2: Sorting
    Here we simply sort the arr and select m array elemnt from i that means grp of m students 
    if arr[i+m-1] - arr[i] is less than prev min then update min
*/
#include<bits/stdc++.h>
using namespace std;

int minDiff(vector<int> vec, int m){
sort(vec.begin(),vec.end());
int n=vec.size();
int min=INT_MAX;
int d=0;
// here we use i+m-1<n rather than i<n because below we checks sets of m elsments 
// when arr contain elaments less that m then for loop not works 
//  if we use then out of bond error ocurs

// revision 3/2/22
// here main logic is that we have to check weather such i to i+m-1 group of candies can we distribute such that diff is minimize
for(int i=0;i+m-1<n;i++){
    d=vec[i+m-1]-vec[i];
    if(d<min){
        min=d;
    }
}
return min;
}
int main(){
    vector<int> vec={7, 3, 2, 4, 9, 12, 56};
    cout<<minDiff(vec,3);
  return 0;
}