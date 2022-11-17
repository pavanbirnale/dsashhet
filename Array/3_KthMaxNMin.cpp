// Find the "Kth" max and min element of an array 
// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1#
// https://leetcode.com/problems/kth-largest-element-in-an-array/

/*
Algo: 
Approch-1 :priority queue ======> TC : O(NLogN)       SC : O(N)
Approch-2 :Sorting  ============> TC : O(NlogN)       SC : O(N)
Approch-3 :Randomizze quick sort  TC : O(N)
*/


// ********* Revision  : 2/2/2022 new code added from line 18 - 55 ******************

#include<bits/stdc++.h>
using namespace std;

// we can reduce the space from O(N)  to O(K) By
//  using Maxheap to calculate kth min element
//  And Using MinHeap to calculate kth Max element

// very less code 11/07/22 
 int kthSmall(vector<int> arr,int k){
    priority_queue<int> pq;
    for(int i=0;i<arr.size();i++){
        pq.push(arr[i]);
        if(pq.size()>k) pq.pop();
    }
    return pq.top();
 }


// TC : O(N)   SC : O(K)
int kthSmallOptimal(vector<int> vec,int k){
    priority_queue<int> maxHeap;
    for(int i=0;i<vec.size();i++){
        if(maxHeap.size()<k){
            maxHeap.push(vec[i]);
        }
        else{
            if(maxHeap.top()>vec[i]){
                maxHeap.pop();
                maxHeap.push(vec[i]);
            }
        }
    }
    return maxHeap.top();
}

// TC : O(N)   SC : O(K)
int kthLargeOptimal(vector<int> vec,int k){
    priority_queue<int,vector<int>,greater<int>> minHeap;
    for(int i=0;i<vec.size();i++){
        if(minHeap.size()<k){
            minHeap.push(vec[i]);
        }
        else{
            if(minHeap.top()<vec[i]){
                minHeap.pop();
                minHeap.push(vec[i]);
            }
        }
    }
    return minHeap.top();
}



// TC : O(N)   SC : O(N)
int kthSmall(vector<int> vec,int k){
    priority_queue<int,vector<int>,greater<int>> pq;
    // +1 is imp and below one also
    for(int i=0;i<vec.size()+1;i++){
        pq.push(vec[i]);
    }
    for(int i=1;i<k;i++){
        pq.pop();
    }
    return pq.top();
}

// // TC : O(N)   SC : O(N)
int kthLarge(vector<int> vec,int k){
    priority_queue<int> pq;
    for(int i=0;i<vec.size();i++){
        pq.push(vec[i]);
    }
    for(int i=1;i<k;i++){
        pq.pop();
    }
    return pq.top();
}
           
int main(){
    vector<int> vec= {6,7,8,1,2,3,4,5,9,12};
    cout<<kthSmallOptimal(vec,5)<<endl;
    cout<<kthLargeOptimal(vec,3)<<endl;
  return 0;
}