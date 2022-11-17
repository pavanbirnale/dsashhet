// Job Scheduling Algo
// Weighted Job Scheduling in O(n Log n) time
// https://www.geeksforgeeks.org/weighted-job-scheduling-log-n-time/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binarySearchd(vector<vector<int>> jobs,int i){
        int lo=0, hi=i-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(jobs[mid][0]<=jobs[i][1]){
                if(jobs[mid+1][0]<=jobs[i][1]){
                    lo=mid+1;
                }
                else{
                    return mid;
                }
            }
            else{
                hi=mid-1;
            }
        }
        return -1;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    
        int n=startTime.size();
        vector<vector<int>> jobs;
        
        for(int i=0;i<n;i++){
            jobs.push_back({endTime[i],startTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end());
        
        int *dp = new int[n];
        dp[0]=jobs[0][2];
        
        for(int i=1;i<n;i++){
            int currProf=jobs[i][2];
            int prevJobIndex=binarySearchd(jobs,i);
            
            if(prevJobIndex != -1){
                currProf+=dp[prevJobIndex];
            }
            dp[i]=max(currProf,dp[i-1]);
        }
        int maxProf=dp[n-1];
        delete[] dp;
        return maxProf;
    }
};
















// optimized
class Solution2 {
public:

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    
        int n=startTime.size();
        vector<vector<int>> jobs(n);
        
        for(int i=0;i<n;i++){
            jobs[i]={endTime[i],startTime[i],profit[i]};
        }
        sort(jobs.begin(),jobs.end());
        
        int dp[n];
        dp[0]=jobs[0][2];
        
        for(int i=1;i<n;i++){
            int currProf=jobs[i][2];
             int lo=0, hi=i-1;
        int prevJobIndex=-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(jobs[mid][0]<=jobs[i][1]){
               prevJobIndex=mid;
               lo=mid+1;
            }
            else hi=mid-1;
        }  
            if(prevJobIndex != -1){
                currProf+=dp[prevJobIndex];
            }
            dp[i]=max(currProf,dp[i-1]);
        }
        return dp[n-1];
    }
};



int main(){
          
  return 0;
}