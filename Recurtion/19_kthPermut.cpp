// Find the K-th Permutation Sequence of first N natural numbers

/*
here what we have to do find the kth permutation of n natuaral numbers string

Approches : 

1 - Brute force : in this approch we have to find all the n! permutaions of string then sort them lexographically 
and return kth permutation
TC : O(n!)* n!log n!
SC : O(n);

2.Optimal Sol : rather that using recurtion we use iterative solution

so firstly we store n munber in an array 
and in fact var factorial of n-1 nums
due to 0 indexed systen k-=1;

In while loop ....
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> arr;
        for(int i=1;i<n;i++){
            fact*=(i);
            arr.push_back(i);
        }
        arr.push_back(n);
        k=k-1;
        string ans = "";
        
        while(1){
            ans+=to_string(arr[k/fact]);
            arr.erase(arr.begin()+k/fact);
            if(arr.size()==0) break;
            k%=fact;
            fact/=arr.size();
        }
        
        return ans;
    }
};
           
int main(){
          
  return 0;
}