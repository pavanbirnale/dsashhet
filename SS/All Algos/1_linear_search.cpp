// linear search or sequential searching algorithm
 /*
 Time complexity: 
 Best Case => O(N)
 Avg. Case => O(N)
 Worst Case => O(N)
 */
#include<bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> vec,int x){
    for(int i=0;i<vec.size();i++){
        if(vec[i]==x){
            return i;
        }
    }
    return -1;
}
           
int main(){
    cout<<linearSearch({1,2,3,4,5},5);
  return 0;
}