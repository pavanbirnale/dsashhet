//maximum sum such that no 2 elements are adjacent
// Stickler Thief
// Approach from pepcoding video
// https://www.youtube.com/watch?v=VT4bZV24QNo

/*
these problem sets base for greedy approach
because in greedy approach we go in some path by excluding remaning paths

here 
*/

#include<bits/stdc++.h>
using namespace std;

int FindMaxSum(int arr[],int n){
    
    //set include and exclude to first array elem and zero 
    int inc=arr[0];
    int exc=0;

    // traverse over the array and find new include and new exclude
    for(int i=1;i<n;i++){
        // new include must made from old exclude by adding curr element
        int ninc = exc+arr[i];

        // new exclude is max between old inc and old exc
        int nexc = max(exc,inc);

// replace old inc and exc
        inc=ninc;
        exc=nexc;
    }
    return max(inc,exc);

}
int main(){
int arr[]={5 ,10 ,10, 100, 5, 6};
cout<<FindMaxSum(arr,6);
  return 0;
}