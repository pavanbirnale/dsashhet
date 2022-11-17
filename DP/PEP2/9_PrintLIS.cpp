// Print Longest Incresing Subsequence




/*
This problems are come in singal group : 

Group 5 : Longest Incressing subsequence (LIS)
1. Longest Incresing Subsequence
2. Maximum Sum Incresing Subsequence
3. Longest Bitonic Subsequences
4. Maximum non Overlaping bridges
5. Russian Doll Problem
6. Perfect Squares
*/




//  image :: https://res.cloudinary.com/darshanscloud/image/upload/v1644575158/ilssda0yi2soral1kocj.png
 
#include<bits/stdc++.h>
using namespace std;

class Paths{
    public:
    int l; //length of Subsequence
    int i; //index 
    // int v; //value
    string psf; 

    Paths(int l,int i,string psf){
        this->l = l;
        this->i = i;
        // this->v = v;
        this->psf = psf;
    }

};
void PrintLIS(vector<int> arr,int n){
     vector<int> dp(n);
     int omax=0;
     int mInd = 0;
     for(int i=0;i<n;i++){
         int ma=0;
        //  find the maximum count such that curr char is greter than all prev
         for(int j=0;j<i;j++){
             if(arr[j]<arr[i]){
                 ma=max(ma,dp[j]);
             }
         }
         dp[i] =ma+1;
         if(omax<dp[i]){
            omax=dp[i];
            mInd =i;
         }
     }
    //  for(auto i : dp) cout<<i<<" ";
     cout<<omax<<endl;
    //  return omax;

    queue<Paths> q;
    q.push(Paths(omax,mInd,to_string(arr[mInd])+""));

    while(!q.empty()){
        Paths rem =q.front();
        q.pop();

        // if length of LIS is reach at 1 then print ans
        if(rem.l==1){
            cout<<rem.psf<<endl;
        }
        // push all the LIS with l=l-1
        for(int j=0;j<rem.i;j++){
            if(arr[j] < arr[rem.i] && dp[j] == rem.l-1){
                q.push(Paths(rem.l-1,j,to_string(arr[j])+" -> "+rem.psf));
            }
        }
    }

}
           
int main(){
    vector<int> arr ={0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
      PrintLIS(arr,16);
  return 0;
}

// arr :  1 2 3 4 5 6 7
// dp  :  1 1 2 3 6 1 2