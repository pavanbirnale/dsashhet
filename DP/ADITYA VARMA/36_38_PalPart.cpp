// Palindromic partitioning
// Similar Problem is present inf recursion 7_palPart  : in this problem we have to print all partition
// in this problem we have to return minimum number of cuts such that new strings are palindrome

// Hard

// Problem statement:
// Given a string str, a partitioning of the string is a palindrome partitioning 
// if every sub-string of the partition is a palindrome. Determine the fewest cuts 
// needed for palindrome partitioning of given string

/*
Steps : 
1). find i and j values 
2). Find base cases
3). move k from i to j
4). use fun to calculate ans
*/

 /*
 Algo : 
 firstly check base cake if string is empty or have one char then also it is palindrome so return 0
 then check weather curr str is palindrome or not is yes then return 0;
 after that check for left and right calls calls and store result if not present
 use k loop from i to j-1 and get minimum parttions
 return ans;
 */
 
#include<bits/stdc++.h>
using namespace std;

// function helper that check weather the given string is palindrome
bool isPal(string str,int i ,int j){
    int lo = i;
    int hi = j;
    while(lo<=hi){
        if(str[lo]!=str[hi]) return 0;
        lo++;
        hi--;
    }
    return 1;
}

// 1). Recursive Function
int PalPartRecurs(string str,int i,int j){
    //  base case if string is empty or have one char then also it is palindrome
    if(i>=j) return 0;
    if(isPal(str,i,j)) return 0;

    int mi = INT_MAX;
    for(int k=i;k<=j-1;k++){
        int temp = PalPartRecurs(str,i,k) + PalPartRecurs(str,k+1,j) + 1;
        mi = min(mi,temp);
    }
    return mi;
}

// 2). Memoization (Bottom Up)     (Not Optimal)
int dp[501][501];
int PalPartMemo(string str,int i,int j){

    if(i>=j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(isPal(str,i,j)) return 0;

    int mi = INT_MAX;
    for(int k=i;k<=j-1;k++){
        int temp = PalPartMemo(str,i,k) + PalPartMemo(str,k+1,j) + 1;
        mi = min(mi,temp);
    }
    return dp[i][j] = mi;
}
           

// 2). Memoization (OPtimal)                  (above approach Gfg accept But interview bit mot accept it)
int PalpartMemoOptimal(string str,int i,int j){
    if(i>=j) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    if(isPal(str,i,j)) return 0;

    int left,right;
    int mi = INT_MAX;

    for(int k=i;k<=j-1;k++){
        // left call separately because it may be present in dp
        if(dp[i][k]!=-1){
            left = dp[i][k];
        }
        else{
            left = PalpartMemoOptimal(str,i,k);
            // storing result here also for next calls
            dp[i][k] = left;
        }

        // also right call separately
        if(dp[k+1][j]!=-1){
            right = dp[k+1][j];
        }
        else{
            right = PalpartMemoOptimal(str,k+1,j);
            // similarly here also
            dp[k+1][j] = right;
        }

        int temp = left + right + 1;
        mi = min(mi,temp);
    } 
    return dp[i][j] = mi;
}

int main(){
     cout<< PalPartRecurs("nitik",0,5);
    //   memset(dp,-1,sizeof(dp));
    //   cout<<PalPartMemo("nitik",0,5);
    //   cout<<PalpartMemoOptimal("nitik",0,5);
  return 0;
}