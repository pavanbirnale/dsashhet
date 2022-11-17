// Binary Search

 /*
It is An decrease and conquer algorithm
also know as interval serching algo
 Time complexity: 
 Best Case => O(1)
 Avg. Case => O(LogN)
 Worst Case => O(LogN)
 */

#include<bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int> vec,int x){
    int s=vec.size();
    int lo=0;
    int hi=s-1;
    while(lo<hi){
        int mid=(lo+hi)/2;
        if(vec[mid]==x) {
            return mid;
        }
        else if(vec[mid]>x){
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    return -1;

}
           
int main(){
  vector<int> vec={1,6,3,4,2};
  cout<<BinarySearch(vec,4);
  return 0;
}