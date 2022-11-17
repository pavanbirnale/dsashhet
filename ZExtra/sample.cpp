#include<bits/stdc++.h> 
using namespace std;

void print(int n){
    if(n==0) return;
    print(n-1);
    cout<<n<<" ";
}

int sum(int n){
    if(n==0) return 0;
    return n+sum(n-1);
}


int fib(int n,vector<int> dp){
    if(n==0 || n==1) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=fib(n-1,dp)+fib(n-2,dp);
}


// find combinations
void combs(vector<int> arr,int size,vector<int> curr,int idx,int i){
    // base case
    if(idx == size){
        for(int j=0;j<size;j++){
            cout<<curr[j]<<" ";
        }
        cout<<endl;
        return;
    }
    if(i>=arr.size()) return;
    // include
    curr[idx] = arr[i];
    combs(arr,size,curr,idx+1,i+1);

    // exclude ---> here we not increases index so the value that updated earlier can be consider as garbage
    combs(arr,size,curr,idx,i+1);

}
int main(){
    // int n=10;
    // vector<int> dp(n+1,-1);
    // cout<<fib(n,dp);
    int size = 3;
    vector<int> arr = {1,2,3,
    4};
    vector<int> curr(size);
    combs(arr,size,curr,0,0);
    return 0;
}