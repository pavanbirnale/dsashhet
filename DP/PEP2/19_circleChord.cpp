//5. Non Intersecting Chords in a Circle

 /*
Group 6 : Catalan Number
1. Catalan Number ans : Cn
2. Count BST with given Nodes ans : Cn
3. Count valleis and Mountains ans : Cn
4. Combinations of Balance Parenthisis ans : Cn
5. Count Non insecting Chords of Circle  ans : Cn/2;
6. Count ways of Polygon Triangulations  ans : Cn-2;

7. Dyck Words
8. Maze Paths above diagonals 
*/

/*
Here in this problem we have given a circle and some points ( this points that mens the input is always even)
*/


#include<bits/stdc++.h>
using namespace std;
           
int  NonIntersectingChords(int n){
     
     vector<int> dp(n+1);
     n=n/2;
     dp[0] = 1;
     dp[1] = 1;

     for(int i=2;i<=n;i++){
         int l = i-1;
         int r = 0;

         while(l>=0){
             dp[i] += dp[l] * dp[r];
             l--;
             r++;
         }
     }
     return dp[n];
}
           
int main(){
      cout<<NonIntersectingChords(8);
  return 0;
}

