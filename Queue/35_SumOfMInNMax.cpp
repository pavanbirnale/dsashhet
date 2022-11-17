// Sum of minimum and maximum elements of all subarrays of size “k”.
// https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/
// ============Hard problem but as a article only==============
// sliding window maximum aproch
#include<bits/stdc++.h>
using namespace std;

int SumOfMinAndMaxInSubarray(vector<int> vec,int k){
    priority_queue<pair<int,int>> maxq;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> minq;
    int sum=0;
    int Max=0;
    int Min=0;
    for(int i=0;i<vec.size();i++){
        while(!maxq.empty() and maxq.top().second<=i-k){
            maxq.pop();
        }
        while(!minq.empty() and minq.top().second<=i-k){
            minq.pop();
        }
        maxq.push(make_pair(vec[i],i));
        minq.push(make_pair(vec[i],i));
        if(i>=k-1){
            sum+=maxq.top().first;
            sum+=minq.top().first;
        }
    }
    return sum;
}

int main(){
    vector<int> vec={2, 5, -1, 7, -3, -1, -2};
        cout<<SumOfMinAndMaxInSubarray(vec,4);
  return 0;
}