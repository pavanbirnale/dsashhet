// https://leetcode.com/problems/find-the-duplicate-number/
// Find the Duplicate Number
// find duplicate in an array of N+1 Integers

/*
Algo:
1st Approch :sort the array and compare linearaly prev and curr element  TC : O(NlogN)
2nd Approch :use the formula nad check for is arr[i]>= 2* size;
*/
#include<bits/stdc++.h>
using namespace std;

int DuplicateNum(vector<int> vec){
    int size=vec.size();
    for(int i=0;i<size;i++){
       vec[vec[i]%size]=vec[vec[i]%size]+size;
    }
    for(int i=0;i<size;i++){
        if(vec[i]>=size*2){
            return i;
        }
    }
    return -1;
}

int main(){
vector<int> vec={1,3,4,2,2};
cout<<DuplicateNum(vec);
return 0;
}

/* 5
1 3 4 2 2
1-> 6 
2-> 14
3-> 7
4-> 7

*/