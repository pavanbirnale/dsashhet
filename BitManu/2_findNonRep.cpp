// https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1

#include<bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int> nums) 
{
    int Xor = 0;
    for(int i : nums){
        Xor^=i;
    }
    int rmsb = Xor & -Xor;
    int x = 0;
    int y = 0;
    for(int i : nums){
        if(i&rmsb) y^=i;
        else x^=i;
    }
    return {min(x,y),max(x,y)};
}

int main(){
       vector<int> arr = {1, 2, 3, 2, 1, 4}
       vector<int> ans = singleNumber(arr);
       cout<<ans[0]<<" "<<ans[1];
    //    3 4 
  return 0;
}