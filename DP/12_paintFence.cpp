
// Painting the Fence
// https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1

// here what we hav eto do is we have to paint n number of fence with k colors such that no more than two fences
// have same color

//  *****************img************** :https://res.cloudinary.com/darshanscloud/image/upload/v1643176274/azttyjvr61s0cz4mni7q.png

// here we have a dp table in that table every cell 

// in row same represent that many ways of paint if ended at previous same color
// same = prev k*1 || (diff * 1) because for prev diff for every diff color we can attached same color
//        but if we use prev same that for every last there allready two same colors present

// in row diff each cell represent that many ways of paint the fence if ended at diffent color
// diff = prev (k*(k-1)) || total*(k-1) expept one color we can paint with all other colors to satisfy the condition of different

// this total require for calculation it is sum of same and diff
// total 

// at last return total;

#include<bits/stdc++.h>
using namespace std;

long long paintingWays(int n,int k){

    // base case
    if(n==1) return k;
    // base cases
    int same = k*1;
    int diff = k*(k-1);
    int total= same+diff;

    for(int i=3;i<=n;i++){
        // we can attach same color only when they are come from diff
        same = diff * 1;
        // same of diff we can attach diff to all totals
        diff = total *(k-1);
        total =same+diff;
    }
    return total;
}
           
int main(){
          cout<<paintingWays(3,2);
  return 0;
}