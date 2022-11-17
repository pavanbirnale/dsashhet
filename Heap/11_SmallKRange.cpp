// Smallest range in K lists
// very interasting problem

#include<bits/stdc++.h>
using namespace std;

// we can use direct vector rather than create our own data type
class element{
    public:
    int val;
    int ap;
    int vp;
    int as;
    element(int value,int arrpos,int valpos,int arrsize){
        val=value;
        ap=arrpos;
        vp=valpos;
        as=arrsize;
    }
};

// operator to comare elem
struct comp{
    bool operator()(element a,element b)
    {
    return a.val > b.val;
    }
};

pair<int,int> smallrange(vector<vector<int>> nums){
    int n=nums.size();

// initializing variables
    int ma=INT_MIN,mi=INT_MAX,lo,hi,range=INT_MAX;
    // createing min heap ans we store cont of max so we only need min evey time
    priority_queue<element,vector<element>,comp> pq;

// pussing first emelnt of every subarr to pq
    for(int i=0;i<n;i++){
        int size_=nums[i].size();
        pq.push(element(nums[i][0],i,0,size_));
        // along with that sore count of max
        ma=max(ma,nums[i][0]);
    }

// then iterate over pq
    while(!pq.empty()){
        // get top elem and check wheater it can form minimum range with max if it can then 
        element temp = pq.top();
        pq.pop();

// change range to maybemin
        int maybemin = ma-temp.val;
        if(range>maybemin){
            range=maybemin;
            // now our lo and hi changes
            lo=temp.val;
            hi=ma;
        }
        // base case : if any arr go to end then we cant find common elemnt next so break and return pre lo and hi
        if(temp.as==temp.vp+1){
            break;
        }
        // incrementing valu possition index every time as index incresses
        temp.vp++;
        // pushing next elemnt to remvoed elemt to pq
        pq.push(element(nums[temp.ap][temp.vp],temp.ap,temp.vp,temp.as));
        // simulteniously updating max
        ma=max(ma,nums[temp.ap][temp.vp]);
    }
    return {lo,hi};
}
int main(){
    vector<vector<int>> nums ={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
          pair<int,int> ans=smallrange(nums);
          cout<<ans.first<<" "<<ans.second;
  return 0;
}