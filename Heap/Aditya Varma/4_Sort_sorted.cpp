// Nearly Sorted Algorithm 
// sort nearly sorted array;
// sort k sorted array

//#aditya varma heap

/*
Algo:
Approch 1: sorting 
sort the array by using any sorting algo buts its time coplexicy goes to o(nlogn);

we known that in problem if their is any word like k,largest or snallest then the problem can be solve by using heap /priority queue

Approch 2: by using heap / priority queue

hear we use priority queue of size k
and use min heap so that we get small elementsat top;
*/
#include <bits/stdc++.h>
using namespace std;
void sortArr(int arr[],int n,int k){
    priority_queue<int,vector<int>,greater<int>> pq;
    int i=0;
    // pushing first k element to pq;
    for(i=0;i<k;i++){
        pq.push(arr[i]);
    }
    // iterate over the array and simulteniously pop top elemnt
    while(i<n){
        cout<<pq.top()<<" ";
        pq.pop();
        pq.push(arr[i++]);
    }
    int s=pq.size();
    // print the array
    while(s--){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    sortArr(arr,n,k);
	}
	return 0;
}