// Matrix Chain Multiplication 
// Hard
// 

/* 
Following Problem are variations of MCM;
1). Matrix Chain Multiplication
2). Palindromic partitioning
3). Evaluate exprestion to true || Boolean Parenthisis
4). Scrambled String
5). Egg Droping
*/



/*
In this problem what we have given a array and we have to return what is the minimum cost of multiplication when we multiply
the matrix in chain manner

basically what we have to do in each recursive call we have given a window from i to j and we have to 
*/

/*
Steps : 
1). find i and j values 
2). Find base cases
3). move k from i to j calculate result in temp
4). use any function to get result from temp
*/

/*
IMP :
Algorithm : 
see 37 line
*/

 
#include<bits/stdc++.h>
using namespace std;


// 1). MCM Recursive :
int MCMRecursive(vector<int> arr,int i,int j){
    // Base case matrix size is 2 so if i and j overcome then return 0
     if(i>=j) return 0;
     int mi = INT_MAX;
    // move k
     for(int k=i;k<=j-1;k++){
        //  1st recursive call gives the min value of multiplication of arr i to k
        //  similarly second recursive call gives the min value of multiplication of arr from k+1 to j
        //  is we add curr cost of multiplication to the recursive calls then we get the minimum multiplication cost of arr from i to j
         int temp = MCMRecursive(arr,i,k) + MCMRecursive(arr,k+1,j) + arr[i-1]*arr[j]*arr[k];
         mi = min(mi,temp);
     }
     return mi;
}

// 2). Bottom Up ( Memoisation)
int dp[101][101];
int MCMMemo(vector<int> arr,int i,int j){
    if(i>=j) return 0;
    // if value is allready present in dp then return from that only
    if(dp[i][j]!=-1) return dp[i][j];

    int mi = INT_MAX;
    for(int k=i;k<=j-1;k++){
        int temp = MCMMemo(arr,i,k) + MCMMemo(arr,k+1,j) + arr[i-1]*arr[j]*arr[k];
        mi = min(mi,temp);
    }
    return dp[i][j] = mi;
}

long long int N = 1e7;
vector<bool> Sieve(int n){
vector<bool> prime(n+1,1);
for (int p = 2; p * p <= n; p++)
{
     if (prime[p] == true) 
     for (int i = p * p; i <= n; i += p) prime[i] = false;
}
return prime;
}
int main(){
    vector<bool> prime = Sieve(100);
        for (int p = 1; p <= 100; p++){
    if (prime[p])
    cout << p <<" "; 
    }
    // vector<int> arr = {40, 20, 30, 10, 30};
    //   cout<<MCMRecursive(arr,1,arr.size()-1);
    //   memset(dp,-1,sizeof(dp));
    //   cout<<MCMMemo(arr,1,arr.size()-1);
  return 0;
}
 