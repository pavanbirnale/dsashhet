// Move all negative numbers to beginning and positive to end with constant extra space
//Article: https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/

// Approch : 1 use Any soring Algo
// Approch : 2 use stl sort
// Approch : 3 Two pointer Approch
/*Algo:
    1. initialize two pointer lo and hi amd then check for four conditions 
    i).if lo is -ve : increment lo++
    ii).if hi is +ve : decrement hi--
    iii).if lo is +ve and hi is -ve : swap both and lo++ ,h--
    iv). both are there require position that means noting to do: lo++ and h--
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> rearrange(vector<int> a){
    int lo=0,hi=a.size()-1;
    while(lo<=hi){
        if(a[lo]<0 and a[hi]<0){
            lo++;
        }
        else if(a[hi]>0 and a[lo]>0){
            hi--;
        }
        else if(a[hi]<0 and a[lo]>0){
            swap(a[lo],a[hi]);
            lo++;
            hi--;
        }
        else{
            lo++;
            hi++;
        }
    }
    return a;
}
           
int main(){
vector<int> v= {-12, 11, -13, -5, 6, -7, 5, -3, 11};
vector<int> ans=rearrange(v);
for(auto i:ans){
    cout<<i<<" ";
}
  return 0;
}
