// Activity Selection Problem  , N meetings in one room
// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#
/*
Greedy Approch :
Greedy is a problem solving technique that works 
In greedy methods we solve the problem step by step or in forms of piece
in eache step find localy optimal solution from that try to reach globaly optimal solution

Greedy works on imidiate benifite principle that means it not thing about to fure and only works on curr
decition and try to optimize things 
greedy not gives every time crrect soltion but can give optimal solution each time
thing the example of path and distimation
https://www.youtube.com/watch?v=0BhhiQGDbEA

in dp we also find optimal soliton like greedy but inthat we check all the possibilty
dp work on :
1.principle of optimility /optimal substructure
2.overlaping subproblem

divide and concur is also same like dp only diffence is that is has non overlaping subproplems



now thing about Activity selection problem:
here what we have to do is find maximum numbers of active that can be donne in particle contionso that not two activitys can overlapd
for that sort the array by end tion and only check is end time of prev metiing is les than start time of 
curr meeting then incress count that mence this meeting that mence this meeting  can be included to meeeting count

*/


   #include<bits/stdc++.h>
   using namespace std;
class meeting{
      public:
      int st;
      int ed;
      int nm;
      meeting(){}
      meeting(int s,int e,int nu){
          this->st=s;
          this->ed=e;
          this->nm=nu;
      }
    };
class Solution{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool comp(meeting m1,meeting m2){
        if(m1.ed<m2.ed) return 1;
        else if(m1.ed>m2.ed) return 0;
        else if(m1.nm<m2.ed) return 1;
        else return 0;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        meeting meet[n];
        int count=0;
        for(int i=0;i<n;i++){
            meet[i]=meeting(start[i],end[i],i+1);
        }
        
        sort(meet,meet+n,comp);
        int prevMeetEndTime =meet[0].ed;
        count++;
        for(int i=1;i<n;i++){
            if(meet[i].st>prevMeetEndTime){
                prevMeetEndTime=meet[i].ed;
                count++;
            }
        }
        return count;
    }
    };
              
   int main(){
        int start[] = {1,3,0,5,8,5};
        int end[] =  {2,4,6,7,9,9};
        Solution s;
        cout<<s.maxMeetings(start,end,6);
     return 0;
   }



   // by class error
/*
class Solution{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    class meeting{
        
      public:
      int st;
      int ed;
      int nm;
      public:
      meeting(int s,int e,int nu){
          this->st=s;
          this->ed=e;
          this->nm=nu;
      }
    };
    bool comp(meeting m1,meeting m2){
        if(m1.ed<m2.ed) return 1;
        else if(m1.ed>m2.ed) return 0;
        else if(m1.nm<m2.ed) return 1;
        else return 0;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        meeting* meet=new meeting*[n];
        int count=0;
        for(int i=0;i<n;i++){
            meet[i]=meeting(st[i],ed[i],i+1);
        }
        
        sort(meet,meet+n);
        int prevMeetEndTime =meet[0].ed;
        count++;
        for(int i=1;i<n;i++){
            if(meet[i].st>prevMeetEndTime){
                prevMeetEndTime=meet[i].ed;
                count++;
            }
        }
        return count;
    }*/




    /*
    // vector sol tle
    class Solution{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.

    static bool comp(vector<int> m1,vector<int> m2){
        if(m1[1]<m2[1]) return 1;
        else if(m1[1]>m2[1]) return 0;
        else if(m1[2]<m2[2]) return 1;
        else return 0;
    }
    int maxMeetings(int start[], int end[], int n)
    {
       vector<vector<int>> meetings(n,vector<int>(3,0));
        int count=0;
        for(int i=0;i<n;i++){
            meetings[i]={start[i],end[i],i+1};
        }
        
        sort(meetings.begin(),meetings.end(),comp);
        int prevMeetEndTime =meetings[0][1];
        count++;
        for(int i=1;i<n;i++){
            if(meetings[i][0]>prevMeetEndTime){
                prevMeetEndTime=meetings[i][1];
                count++;
            }
        }
        return count;
    }
    */