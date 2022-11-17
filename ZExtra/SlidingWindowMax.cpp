// https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
// Sliding Window Maximum (Maximum of all subarrays of size k)
// https://leetcode.com/problems/sliding-window-maximum/

/* 
Approch 1: Brute Force -
    use two for loops Outer loop run N times and inner loops runs 
    k times like these traverse all windows and print max from each window
    TC :O(N*K) SC :O(1)

Approch 2: By Deque 
    similer like pq only operation names gates chenges

Approch 3: Heap (Priority Queue)-
USes pair in pq for maintaing index also
By default pq store maximun elemnt at top and when we insert new elment 
of pq then due to heapification ax element comes at top.
by ushing these property we can find maximum elemnt in each window 
    a).Algo -1: like our noral approch 
        i)push first k elment to pq 
        ii).then push remaining elemnts in another for loop and simultenioyusly
        check of pop condition also wheter the max elemnt goes out of pq or not.
    ======THese Approch gives TLE in GFG================
    b).Algo -2: like leetcode solution
        So we use single for loop rather thantwo sepater for loops and in that 
        check fo pop condition and push to vector untill pq size reaches to k

*/
#include<bits/stdc++.h>
using namespace std;

// normal Approch
vector<int> MaxInWindow(vector<int> vec,int k){
    priority_queue<pair<int,int>> pq;
    vector<int> ans;
    for(int i=0;i<k;i++){
        pq.push(make_pair(vec[i],i));
    }
    ans.push_back(pq.top().first);
    for(int i=k;i<vec.size();i++){
        while(pq.top().second<=i-k) pq.pop();
        pq.push(make_pair(vec[i],i));
        ans.push_back(pq.top().first);
    }
return ans;
}

// gfg and leetcode aprroch
vector<int> MaxInWindow2(vector<int> vec,int k){
    vector<int> ans;
    priority_queue<pair<int,int>>pq;
    for(int i=0;i<vec.size();i++){
        while(!pq.empty() and pq.top().second<=i-k) pq.pop();
        pq.push(make_pair(vec[i],i));
        if(i>=k-1){
            ans.push_back(pq.top().first);
        }
        return ans;
    }
}

int main(){
    vector<int> vec={8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
    vector<int>ans=MaxInWindow(vec,4);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
  return 0;
}