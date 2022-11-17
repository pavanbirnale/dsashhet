#include<bits/stdc++.h>
using namespace std;
string reverseWord(string str){
    
    // stl reverse also used
    int lo=0;
    int hi=str.size()-1;
    while(lo<hi){


      
        swap(str[lo],str[hi]);
        lo++;
        hi--;
    }
    return str;
}
           
int main(){
          
  return 0;
}