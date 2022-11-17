// Tug of War
// https://www.geeksforgeeks.org/tug-of-war/
// Artilcle

// tub of war is an game known as rassi khech in marathi
//  in this problem what we have to do is diveid the array into two part have n/2 size ( in odd n case one array has 1+ more size)
// adding array elems in them such way  taht differnce of sum of all ements of indivial arry is minimmum
#include<bits/stdc++.h>
using namespace std;


vector<int> ans1 ={};
vector<int> ans2 ={};
void tugOfWarMinDiff(vector<int> arr,int idx,int &msf,vector<int> set1,vector<int> set2,int set1Sum,int set2Sum){
    // base case
    if(idx==arr.size()){
        int diff = abs(set1Sum-set2Sum);
        if(msf>diff){
            msf =diff;
            // for(int)



// incomplete





        }  
        return;
    }

// 1+ in size wich hanndel odd even condition
    if(set1.size() < (arr.size()+1)/2){
        set1.push_back(arr[idx]);
        set1Sum+=arr[idx];
        tugOfWarMinDiff(arr,idx+1,msf,set1,set2,set1Sum,set2Sum);
        set1Sum-=arr[idx];
        set1.pop_back();
    }

    if(set2.size() < (arr.size()+1)/2){
        set2.push_back(arr[idx]);
        set2Sum+=arr[idx];
        tugOfWarMinDiff(arr,idx+1,msf,set1,set2,set1Sum,set2Sum);
        set2Sum-=arr[idx];
        set2.pop_back();
    }
}
           
int main(){
    vector<int> arr ={23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
    vector<int> set1={};
    vector<int> set2={}; 
    int msf = INT_MAX;
    tugOfWarMinDiff(arr,0,msf,set1,set2,0,0);
    cout<<msf;
  return 0;
}