// Code to Generate All Substrings of String

// TC : O(n^3);
// SC : O(1);
// there are n*(n+1)/2 non-empty Substrings for n length String.
 
 
#include<bits/stdc++.h>
using namespace std;
           
vector<string> GenerateSubString(string str){
     int n = str.size();
     vector<string> ans;
     for(int i=0;i<n;i++){
         for(int j=i;j<n;j++){
             string temp = "";
             for(int k=i;k<=j;k++){
                 temp+=str[k];
             }
             ans.push_back(temp);
         }
     }
     return ans;
}
           
int main(){
    string str = "ABC";
      vector<string> ans = GenerateSubString(str);
      for(auto i : ans){
          cout<<i<<endl;
      }
  return 0;
}