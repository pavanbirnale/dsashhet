// Count and Say problem
// https://leetcode.com/problems/count-and-say/submissions/
#include<bits/stdc++.h>
#include<string>
using namespace std;


    string countAndSay(int n) {
       if(n==1) return "1";
       if(n==2) return "11";
        string s="11";
        for(int i=3;i<=n;i++){
            string t="";
            s+='&';
            int c=1;
            for(int j=1;j<s.length();j++){
                if(s[j]!=s[j-1]){
                    t+=to_string(c);
                    t+=s[j-1];
                    c=1;
                }
                else {
                    c++;
                }
            }
            s=t;
        }
        return s;
    }
           
int main(){
    cout<<countAndSay(3);
  return 0;
}