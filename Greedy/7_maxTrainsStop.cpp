// Maximum trains for which stoppage can be provided
// https://www.geeksforgeeks.org/maximum-trains-stoppage-can-provided/
// Article

/*
Algo:
sort the data by incresing order of departure time 
create an arr of platform with n+1 size due to 0 proble
ininitialize platfform arr with {-1,-1} pair

then only check is the platform is book or not
if not book tj=hen book it 

and if booked then what is departure time of previous train
if it is less then increment count and set that train to platform
*/

#include<bits/stdc++.h>
using namespace std;

static bool comp(vector<int> d1,vector<int> d2){
    return d1[1]<d2[1];
}
// data[]={start time,departure time,platform num}
int MaxTrains(vector<vector<int>> data,int numOfTrains,int numOfPlatform){
    int n=data.size();
    sort(data.begin(),data.end(),comp);

    int trainsCount=0;
    vector<pair<int,int>> platforms(numOfPlatform,{-1,-1});
    for(int i=0;i<n;i++){

        int isPlatformBooked=platforms[data[i][2]].first;

        if(isPlatformBooked==-1){
            trainsCount++;
            platforms[data[i][2]] = make_pair(data[i][0],data[i][1]);
        }
        else{
            if(platforms[data[i][2]].second<data[i][0]){
                trainsCount++;
                platforms[data[i][2]] = make_pair(data[i][0],data[i][1]);
            }
        }
    }
return trainsCount;
}
           
int main(){
   vector<vector<int>> data={
                     { 1000, 1030, 1},
                      {1010, 1020, 1},
                      {1025, 1040, 1},
                     { 1130, 1145, 2},
                      {1130, 1140, 2} };
                    //   {1000, 1030, 1},
                    //   {1010, 1030, 1},
                    //   {1000, 1020, 2},
                    //   {1030, 1230, 2},
                    //   {1200, 1230, 3},
                    //   {900, 1005, 1} };

                    //   {1000, 1030, 0},
                    //   {1110, 1130, 0},
                    //   {1200, 1220, 0} };

  cout<<MaxTrains(data,5,3);
  return 0;
}