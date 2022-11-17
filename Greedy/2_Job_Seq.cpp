// Job Sequencing Problem
// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
// Greedy

/*
Here in this problem we have several jobs with job num,deadline and profit for each job and 
what we have todo is that find the maximum profit by doing this jobs with in the dead line
*/
#include<bits/stdc++.h>
using namespace std;

class Job{
public:
int num;
int dead;
int profit;

Job(){}

Job(int n,int d,int p){
    num=n;
    dead=d;
    profit=p;
}

};
class Solution{
    public:
    static bool comp(Job a,Job b){
        return a.profit > b.profit;
    } 
    vector<int> maxProfit(Job arr[],int n){
        // sort the array by profit in decreasing order
         sort(arr,arr+n,comp);
        //  for checking slots user vector as timeline and move from deadline to left side 
        // important stemp that means create and vector to manage the total number of jobs
         vector<int> jobs(n+1,0);
         int JobsC=0;
         int JobsP=0;
         for(int i=0;i<n;i++){
             int j= min(n,arr[i].dead);
            //  check if slot are available or not
             while(j>0){
                 if(jobs[j]==0){
                     jobs[j]=1;
                     JobsC++;
                     JobsP+=arr[i].profit;
                     break;
                 }
                 else j--;
             }
         }
         return { JobsC,JobsP};
     }
};
           
int main(){
          
  return 0;
}