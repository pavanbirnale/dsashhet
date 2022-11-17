// 2.Count Number of Binary Search Trees with N Nodes

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
Here in this problem we have given number of nodes of bst and we have to return count of distinct Bst that are
form by that nodes.
here ans is we can form Cn number of trees with n number of nodes
*/


#include<bits/stdc++.h>
using namespace std;
           
int  CountBst(int n){
     
     vector<int> dp(n+1);

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
      cout<<CountBst(4);
  return 0;
}