// Find Longest Recurring Subsequence in String
// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    int n=str.length();
            // create an dp table
		    int dp[n+1][n+1];
		    for(int i=0;i<=n;i++){
		        for(int j=0;j<=n;j++){
                    // no subseq with i and j zero
		            if(i==0 || j==0){
		                dp[i][j]=0;
		            }
                    // if charecters at different index are same then increment the length of repeting subseq
		            else if(str[i-1]==str[j-1] && i!=j){
		                dp[i][j]=dp[i-1][j-1]+1;
		            }
		            else{
                        // if chars are not same or iand j not same then simply continue with prev max elemet
		                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		            }
		        }
		    }
		    return dp[n][n];
		}

};
int main(){
          
  return 0;
}