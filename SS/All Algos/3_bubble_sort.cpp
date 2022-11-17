// Bubble Sort
// https://practice.geeksforgeeks.org/problems/bubble-sort/1#
/*
Algorithm:
Bubble sort is basic ,simple sorting algorithm

Time Complexity : 
Best Case => O(N)
Avg. Case => O(N^2)
Worst Case => O(N^2)

Optimal Bubble sort =>
every time we use a flag to false if any swaping occurs then change these flag to 
true and at last check the flag that if it false or not if it is false that means not 
any swap occurs so data is sorted that avoid the next useless passes
*/

#include<bits/stdc++.h>
using namespace std;

// swaping if left is greater than right
void swaping(int &a,int &b){
      int temp=a;
      a=b;
      b=temp;
}

void bubbleSort(vector<int> &vec){
    int s=vec.size();
    // use to passes with O(N^2) complexities
    for(int i=0;i<s-1;i++){
        bool f=0;
        for(int j=0;j<s-i-1;j++){
            if(vec[j]>vec[j+1]){
                f=1;
                swaping(vec[j],vec[j+1]);
            }
            if(f==0) break;
        }
    }
}
// 1 6 3 4 2
// 1 2 3 4 6
           
int main(){
    vector<int> vec={1,6,3,4,2};
    bubbleSort(vec);
    for(auto i:vec){
        cout<<i<<" ";
    }
  return 0;
}