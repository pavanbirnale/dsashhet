// Minimum Platforms Problem;
// Minimum Platforms
// https://youtu.be/dxVcMDI7vyI see video



#include<bits/stdc++.h>
using namespace std;

int maxPlatform(int arr[],int dep[],int n){
    // sort the arrays
    sort(arr,arr+n);
    sort(dep,dep+n);

// and handdle count of currPlatform by Two pointer approch
    int currPlatform=1;
    int maxPlatform=1;

    int i=1,j=0;

    while(i<n && j<n){
        if(arr[i]<=dep[j]){
            currPlatform++;
            i++;
        }
        else if(arr[i]>dep[j]){
            currPlatform--;
            j++;
        }
        maxPlatform=max(maxPlatform,currPlatform);
    }
    return maxPlatform;
}

int main(){
    int arr[] = {900, 940, 950, 1100, 1500, 1800}; 
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};     
          cout<<maxPlatform(arr,dep,6); 
  return 0;
}


// my code gives WA
  // 	vector<pair<int,int>> TrainsData;
    // 	for(int i=0;i<n;i++){
    // 	    TrainsData.push_back({arr[i],dep[i]});
    // 	}
    // 	sort(TrainsData.begin(),TrainsData.end(),comp);
    	
    // 	for(int i=1;i<TrainsData.size();i++){
    // 	    int prevTrainDeprT=TrainsData[i-1].second;
    // 	    if(prevTrainDeprT<TrainsData[i].first){
    // 	        TrainsData.erase(TrainsData.begin()+(i-1));
    // 	        i--;
    // 	    }
    // 	    else{
    // 	        int j=i-1;
    // 	        while(j>=0){
    // 	           if(TrainsData[j].second>TrainsData[i].first){
    // 	               j--;
    // 	           } 
    // 	           else{
    // 	               TrainsData.erase(TrainsData.begin()+j);
    // 	               break;
    // 	           }
    // 	        }
    // 	    }
    // }
    //     return TrainsData.size();