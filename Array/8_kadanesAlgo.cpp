//kadanes Algorithm or maximun=m sum of subarray
// https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1#

// Algo Train like and family like approch
/*
1. set currmax and overall max to 1 vector element
2. then iterate over vect and check the conditiopns:
    i). if prevs sum is gretter than zero then next must be add with iit 
    ii) if prev or currmax goes to -ve then start new train from next elment 
    iii). third condition for checking overall maximum 
*/
#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> vec)
{
  int currMax = vec[0];
  int overAllMax = vec[0];

  for (int i = 1; i < vec.size(); i++)
  {

    if (currMax > 0)
    {
      currMax += vec[i];
    }
    else {
      currMax=vec[i];
    }
    if(currMax>overAllMax){
      overAllMax=currMax;
    }

  }
  return overAllMax;
}
int main()
{
   vector<int>  vect={1,-10,5,14,-8,10,12,-13};
   cout<<maxSubarraySum(vect);
  return 0;
}