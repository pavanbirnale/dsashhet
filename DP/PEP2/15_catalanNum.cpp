// 1. Catalan Number

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

// Cn = Cn-1*C0 + Cn-2*C1 + Cn-3*C2 + ...........+ C1*Cn-2 + C0*Cn-1;
// we cant find catalan of n directly for that we always needs catalan of n-1
// so Cn+1 = 2(2n+1)/(n+2)Cn;
// hence Cn ~ 4^n/[n^(3/2) * (PI)^-1/2;
// In combinatorial mathematics catalan numbers are sequence of natural numbers that are occurs in many counting problems
// There are many application of catalan numbers



#include<bits/stdc++.h>
using namespace std;

// function return nth Catalan Number
int catalanNum(int n){
     

    vector<int> dp(n+1);

// Base Case
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2;i<=n;i++){

        int l = i-1;
        int r = 0;
        while(l>=0){
            dp[i] += dp[l]*dp[r];
            l--;
            r++;
        }
    }
    return dp[n];
}
           
int main(){
      cout<<catalanNum(5)<<endl;
  return 0;
}