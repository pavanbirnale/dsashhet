// https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1#
// Find if there is any subarray with sum equal to 0
// Approch 1 : Brute Force
// Approch 2 : Prefix Sum :
/*
here a simple prefix sum approch is used 
In prifix sum we simply add curr element to perv sum
After adding new element we can check three conditions:
    i).  sum==0
    ii). is arr contains zero then also given condition mathches
    iii).is prefix sums arr contain duplicate element
In easy word , we only check if duplicate elemnts are present in set or not
if is is present then there are such element is array whose sum must be equal to zero
// here we push sum to set so id=f sum get decrease after increas the such subarray is present
*/
#include<bits/stdc++.h>
using namespace std;

bool subarraySum0BruteForce(vector<int> vec){
    int s=vec.size();
    int sum=0;
    for(int i=0;i<s;i++){
        sum=0;
        for(int j=i;j<s;j++){
            sum+=vec[j];
            if(sum==0){
                return 1;
            }
        }
    }
    return 0;
}

bool subArrSum0(vector<int> vec){
    int s= vec.size();
    int sum=0;
    set<int> st;
    for(int i=0;i<s;i++){
        sum+=vec[i];
        if(sum==0 || vec[i]==0){
            return 1;
        }
        st.insert(sum);
    }
    return st.size()<s;
}

int main(){
   vector<int> v={4, 2, -3, 1, 6};
   cout<<subarraySum0BruteForce(v)<<"\n";
   cout<<subArrSum0(v)<<"\n";
  return 0;
}
