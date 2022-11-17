// Total Decoding Messages 
// NISBOGFG =>> https://practice.geeksforgeeks.org/problems/total-decoding-messages1235/1/#

// https://www.youtube.com/watch?v=jFZmBQ569So&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=20

/*
Algo : 
In this algo what we do is we traverse on string and check i-1th and its next charecter every time 
in if else loop this log is handdle
*/

#include<bits/stdc++.h>
using namespace std;

long long int M=1e9+7;

int CountWays(string str){

    int n =  str.size();

    // base cases
    if(str[0] == '0') return 0;
    for(int i = 0; i < n-1; i++) {
        if(str[i] == '0' && str[i+1] == '0')
        return 0;
    }


    vector<int> dp(n);
    dp[0] = 1;
    for(int i=1;i<n;i++){
        
        // both are zero => dp[i] = 0;
        // commented on 30-3-22 Revision because belowcondition is allready checked
        // if(str[i-1] == '0' && str[i] == '0') {dp[i] = 0;}
        
        // first is zero and second is non zero dp[i] = dp[i-1];
        if(str[i-1] == '0' && str[i] !='0') {dp[i] = dp[i-1];}
        
        //first is non zero and second is zero like 10,20,30,40
        else if(str[i-1] != '0' && str[i] == '0'){
            if(str[i-1] == '1' || str[i-1] == '2'){
                dp[i] = (i>=2 ? dp[i-2] : 1);
            }
            else{
                dp[i] = 0;
            }
        }
        
        //both are non zero
        else { 
            //cout<<i<<" "<<str.substr(i-1,2)<<endl;
            if(stoi(str.substr(i-1,2))<=26){
                dp[i] = (dp[i-1]+(i>=2 ? dp[i-2] : 1))%M;
            }
            else{
                dp[i] = dp[i-1];
            }
        }
        
    }
    // loop for printing dp
    // for(auto i : dp) cout<<i<<" ";
    // cout<<endl;
    return dp[n-1];
}



int main(){
	cout<<CountWays("123");
	return 0;
} 