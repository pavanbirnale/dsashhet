// Count Binary Strings 
// NISBOGFG    =>>   https://www.geeksforgeeks.org/count-number-binary-strings-without-consecutive-1s/

// ozc = old zero count
// ooc = old one count
// nzo = new zero count
// noc = new one count

// n          => 0  1  2   3   4    5    6     7   8
// zero count => 1  1  2   3   5    8    13    21  34
// one  count => 1  2  3   5   8    13   21    34  55

// here zero count is prev one count and one count is prev zero + one count
// because we can append one with one but not zero with zero so 
// new one count can be achieved by appending 1 to both old zero and one count 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M =1e9+7;

ll countStrings(int n){

    int ozc = 1;
    int ooc = 1;
    n--;
    while(n--){
        int nzc = ooc;
        int noc = (ozc+ooc)%M;

        ozc = nzc;
        ooc = noc;
    }
    return (ozc+ooc)%M;
}
int main(){
    cout<<countStrings(3);
  return 0;
}