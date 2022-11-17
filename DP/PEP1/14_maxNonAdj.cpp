//    Allready solved see comments of that code for more understanding
                        //  Stickler Thief : D:\dataStructure\DSASheet\SS\12_SticklerThief.cpp
// Maximum Sum Non Adjacent Elements 
// https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1
// https://www.youtube.com/watch?v=VT4bZV24QNo&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=22

#include<bits/stdc++.h>
using namespace std;

int MaxNonAdjSum(vector<int> arr){
    int inc = arr[0];
    int exc = 0;

    for(int i=1;i<arr.size();i++){
        // we only include on previous exclude 
        int ninc = exc + arr[i];

        // new exclude is max of previos exclude and include
        int nexc = max(inc ,exc);

        inc = ninc;
        exc = nexc;
    }
    return max(inc,exc);
}
           
int main(){
  vector<int> arr={5 ,10 ,10, 100, 5, 6};
  cout<<MaxNonAdjSum(arr);
  return 0;
}