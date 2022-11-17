// Boolean Parenthesization || Evaluate Expression To True
// premium on Leetcode    ==>(Hoops get Lost)  
// very nice article : https://leetcode.com/discuss/general-discussion/1279635/boolean-parenthesization-easy-c

 /*
 Algo : 
 1).find i and j value
 2). Find Base Cases
 3). move k from i to j and eval ans acc to operator and istrue
 */
 
#include<bits/stdc++.h>
using namespace std;
int dp[201][201][2];
int EvalExpRec(string s, int i, int j, bool istrue)
{
    // Base case if i overcame j then return 0;
    if(i>j) return 0;

    // if onl single char is present and we needs istrue then return wheather the s[i] is T or not
    if(i == j){
        if(istrue) return s[i] == 'T';
        else return s[i] == 'F';
     }

    //  check in dp
    if(dp[i][j][istrue] != -1) return dp[i][j][istrue];
    int ans = 0;

    // move k from one operationr to another from left to right with 2 steps
     for(int k = i+1;k<j;k+=2){

// this all four cases are for some times we needs false case also to evaluate true result 
// for eq in case of or and xor we get T*F = T so we calculate all cases 
        int ltrue = EvalExpRec(s,i,k-1,1);
        int lfalse = EvalExpRec(s,i,k-1,0);
        int rtrue = EvalExpRec(s,k+1,j,1);
        int rfalse = EvalExpRec(s,k+1,j,0);

    // now from that cases evaluate ans accordingly weather we needs istrue of false
        if(s[k]=='&'){
            if(istrue){
                ans= (ans + (ltrue*rtrue)%M)%M; 
            }
            else{
                ans= (ans + (ltrue*rfalse)%M + (lfalse*rtrue)%M + (lfalse*rfalse)%M)%M;
            }
        }
        else if(s[k]=='|'){
            if(istrue){
                ans= (ans + (ltrue*rtrue)%M + (ltrue*rfalse)%M + (lfalse*rtrue)%M)%M;
            }
            else{
                ans= (ans + (lfalse*rfalse)%M)%M;
            }
        }
        else {
            if(istrue){
                ans= (ans + (ltrue*rfalse) % M + (lfalse*rtrue) % M )%M;
            } 
            else{
                ans= (ans + (ltrue*rtrue) % M + (lfalse*rfalse) % M )%M;
            }
        }
    }
    return dp[i][j][istrue]=ans;
    }
int EvalExpRecw(string s,int i,int j,bool isTrue){
    memset(dp,-1,sizeof(dp));
    return EvalExpRec(s,i,j,isTrue);
}
int main(){
    string s = "T|T&F^T";



    // this s.size()-1 has taken one day to undersand





    cout<<EvalExpRecw(s,0,s.size()-1,1);
  return 0;
}