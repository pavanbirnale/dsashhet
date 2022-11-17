
// Jugad but but successful
// #include <bits/stdc++.h>
// using namespace std;
// void sortArr(unordered_map<int,int> mp){
//     priority_queue<pair<int,int>> pq;
//     for(auto itr: mp){
//         pq.push({itr.second,itr.first});
//     }
//     int s=pq.size();
//     while(s--){
//         for(int i=0;i<pq.top().first;i++){
//             cout<<pq.top().second<<" ";
//         }
//         pq.pop();
//     }
// }
// int main() {
// 	int t;
// 	cin>>t;
// 	while(t--){
// 	    int n;
// 	    cin>>n;
// 	    unordered_map<int,int> mp;
// 	    for(int i=0;i<n;i++){
// 	        int x;
// 	        cin>>x;
// 	        mp[x]++;
// 	    }
// 	    sortArr(mp);
// 	    mp.clear();
// 	    cout<<endl;
// 	}
// 	return 0;
// }



#include <bits/stdc++.h>
using namespace std;
void sortArr(int arr[],int n){
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    
    sort(arr,arr+n,[&](int a,int b){
        if(mp[a]!=mp[b]) return mp[a] > mp[b];
    return a < b;
    });
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	  int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    sortArr(arr,n);
	}
	return 0;
}