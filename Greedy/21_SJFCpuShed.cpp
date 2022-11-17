// Program for Shortest Job First (or SJF) CPU Scheduling
// This algorithm is part of OS
/*
their are certain another algo similar like this 
1.First come first serve
2.sortest job first


in this approch what machine does that exicute the sortest job first at that time so os can free for next long jobs

algo:
1.sort the jobs acording to arival time if it same then a/c to brust time it is also same then acording to id

push one by one jobs to pq (min heap)
which gives job acording to min brust time

them pop that job and set as that job is done and now
push new job if its ariving time is greater that curr total time
*/
#include<bits/stdc++.h>
using namespace std;

static bool comp(vector<int> j1,vector<int> j2){
    if(j1[1]==j2[1]){
        if(j1[2]==j2[2]){
            return j1[0]<j2[0];
        }
        else{
            return j1[2]<j2[2];
        }
    }
    else{
        return j1[1]<j2[1];
    }
}
vector<int> SortestJobFirst(vector<vector<int>> Jobs,int n){
sort(Jobs.begin(),Jobs.end(),comp);
vector<int> ans;
int TotalTime=0;
priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
pq.push({Jobs[0][2],Jobs[0][1],Jobs[0][0]});

int i=1;
while(!pq.empty()){
    int bustTime =pq.top()[0];
    int id=pq.top()[2];

    pq.pop();
    ans.push_back(id);
    TotalTime+=bustTime;
    while(1){
        // this second condition if for for evry new stask arival time must be less that 
        // total time because we cannt exicutethe stacks in future if cetain gap is tere
        if(i<n && Jobs[i][1]<=TotalTime){
            pq.push({Jobs[i][2],Jobs[i][1],Jobs[i][0]});
            i++;
        }
        else{
            break;
        }
    }
}
return ans;
}
           
int main(){
vector<vector<int>> arr ={{1,2,3},{2,0,4},{3,4,2},{4,5,4}};
vector<int> ans =SortestJobFirst(arr,4);

for(int i=0;i<4;i++){
    cout<<ans[i]<<" ";
}
  return 0;
}