// Combinations

#include<bits/stdc++.h>
using namespace std;

void combinations(int currBox , int totalBox , int ballCountSf,int totalBalls ,  string asf){

    if(currBox > totalBox){
        if(ballCountSf==totalBalls)
        cout<<asf<<"\n";
        return;
    }

    combinations(currBox+1,totalBox,ballCountSf+1,totalBalls,asf+" B ");
    combinations(currBox+1,totalBox,ballCountSf,totalBalls,asf+" - ");
}
           
// this are the six way to put the same ball in four boxes

// 2^4 = 4C0 + 4C1 + 4C2 + 4C3 + 4C4 
// 16  = 1   + 4   + 6   + 4   +  1;

// nCr = n!/ r! * (n-r)!  boxes on level 


// nPr = n! / (n-r)!   ball on level

/*
 B  B  -  - 
 B  -  B  - 
 B  -  -  B 
 -  B  B  - 
 -  B  -  B 
 -  -  B  B 
 */


// find combinations
void combinations123(vector<int> arr,int size,vector<int> curr,int idx,int i){
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
    combinations123(arr,size,curr,idx+1,i+1);

    // exclude ---> here we not increases index so the value that updated earlier can be consider as garbage
    combinations123(arr,size,curr,idx,i+1);

}

/*
1 2 3 
1 2 4 
1 3 4 
2 3 4 
*/

int main(){
   combinations(1,4,0,2,"");

    int size = 3;
    vector<int> arr = {1,2,3,
    4};
    vector<int> curr(size);
    combinations123(arr,size,curr,0,0);
  return 0;
}
