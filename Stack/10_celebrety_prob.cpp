// The Celebrity Problem

/*Two approches:
1. TC:O(N^2)    SC:O(N)
2. TC:O(N)      SC:O(1)
*/
#include<bits/stdc++.h>
using namespace std;

// Approch: 1
int celebrity(vector<vector<int>> &a,int n){
    // these is brute force approch and mains data of every person 
    // who knows to him and to whome he knows
    // by two for loops
    int in[n]={0};
    int out[n]={0};

    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            if(a[i][j]==1){
                in[j]++;
                out[i]++;
            }
        }
        }
        // check the the person whos not know anyone but all other khows him
        for(int i=0;i<n;i++){
            if(in[i]==n-1 && out[i]==0){
                return i;
            }
        }
    
    return -1;
}

// Approch: 2

int celebrity2(vector<vector<int>> &a,int n){
    // first assume 0 as celebrity then itrate over matrix and check
    // if c knows to someone or not
    // if it knows to some one so it not a celebrity and then move to next i and consider it as celebrity
    int c=0;
    for(int i=1;i<n;i++){
        if(a[c][i]==1){
            c=i;
        }
    }
    // finaly check for celeb that is i!= c and anothr false condition
    // if celebknows to someone  or someone not  knows to celeb then return -1 else return c;
    for(int i=0;i<n;i++){
        if(i!=c and (a[c][i]==1 or a[i][c]==0)) return -1;
    }
    return c;
}
           
int main(){
          
  return 0;
}