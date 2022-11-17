// 4.Combinations Of Balance Parenthisis

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
In this problem what we have to do is we have given n pairs of opening and closing brackets and we have to return the count that how many balance paranthesis can form by combinations of them

ONE Condition is for every pair clossing bracket count never exceed the opening brackets
*/


#include<bits/stdc++.h>
using namespace std;
           
int  balParenthisis(int n){
     
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
      cout<<balParenthisis(4);
  return 0;
}