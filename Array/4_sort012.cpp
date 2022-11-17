// Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo;
// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1#
// https://leetcode.com/problems/sort-colors/

/*
Two Approches:
1st Brute force count all the zeros ones and twos and then separately print them  TC:O(n) SC:O(1)

2nd Use Three pointer approch TC:O(n) SC:O(1)
    1).set initially lo and mid to 0 and hi to last array index
    2).then iterate over the array and check if the upcoming elemrnt is 0 1 or 2
    3).if(a[i]==0)then swap a[lo] and a[mid] and increse lo and mid by one
    4).else if(a[i]==2)then swap a[hi amd a[mid] and decrese hi
    5). else for A[i]==1 only increse mid++  
*/

#include<bits/stdc++.h>
using namespace std;

void sort0122(int a[], int n){
int z=0,o=0,t=0;
        for(int i=0;i<n;i++){
            if(a[i]==0)z++;
            else if(a[i]==1)o++;
            else if(a[i]==2)t++;
        }
        
        while(z>0){
            cout<<0<<" ";
            z--;
        }
        while(o>0){
            cout<<1<<" ";
            o--;
        }
        while(t>0){
            cout<<2<<" ";
            t--;
        }
}


 void sort012(int a[], int n)
    {
        int lo=0,mid=0,hi=n-1;
        while(mid<=hi){
            if(a[mid]==0){
                swap(a[lo],a[mid]);
                lo++;
                mid++;
            }
            else if(a[mid]==2){
                swap(a[hi],a[mid]);
                hi--;
            }
            else{
                mid++;
            }
        }
    }
int main(){
          
  return 0;
}