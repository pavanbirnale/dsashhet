// Maximum difference of zeros and ones in binary string
// Application of Kadane's Algorithm


/*
What ? => We ahve given A binary string and we have to find the maximum difference of number of zeros and ones in any substring
Edge case :  In case of all one return -1;

Eg : for string 11000010001 From index 2 to index 9,there are 7 0s and 1 1s, so number of 0s - number of 1s is 6.

How ? : 

1). Brute Force : Find all substrings in O(N^3) and cout 1 and 0 in between them and subtract count maintain maximum among them.

2). By using kadane's Algorithm :
By replacing all 1s to -1 and zero to 1s
and r=then use normal Kadane's algorithm
*/

 
 
#include<bits/stdc++.h>
using namespace std;
           
int maxDiff(string s){
     int n = s.size();
     vector<int> arr(n);
    //  Replacemnt
     for(int i=0;i<n;i++){
         if(s[i]=='1') arr[i] = -1;
         else arr[i] = 1;
     }

    //  kadane's Algorithm
     int currMax = arr[0];
     int overMax = arr[0];

     for(int i=1;i<n;i++){
         if(currMax>0){
             currMax += arr[i];
         }
         else{
             currMax = arr[i];
         }
         overMax = max(overMax,currMax);
     }
     return overMax;
}
           
int main(){
      f();
  return 0;
}