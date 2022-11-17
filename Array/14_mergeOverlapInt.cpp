// Merge Intervals Merge overlaping Intervals 
// https://leetcode.com/problems/merge-intervals/

/*
Algo:
Approch 1 : Naive Approch : traverse the array by two loops and check the same condition like efficient approch
Approch 2 : sorting and checking
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergedIntervals(vector<vector<int>> intervals){
    vector<vector<int>> merged;
    sort(intervals.begin(),intervals.end());
    for(auto itr:intervals){
        if(merged.empty() || merged.back()[1]<itr[0]){
            merged.push_back(itr);
        }
        else{
            merged.back()[1]=max( merged.back()[1],itr[1]);
        }
    }
    return merged;
}

int main(){
vector<vector<int>> vec={{1,3},{2,6},{8,10},{15,18}};
vector<vector<int>> ans= mergedIntervals(vec);
for(auto i:ans){
    cout<<"{"<<i[0]<<","<<i[1]<<"}";
}
// [[1,6],[8,10],[15,18]]
  return 0;
}