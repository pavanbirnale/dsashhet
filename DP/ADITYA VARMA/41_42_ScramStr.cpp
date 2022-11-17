// Scrambled String 
// Not In DSA Sheet

/*
What ? : In this problem we ahve given two strings a nad b and we have to return wheather this two string are scramabled or not
in first look this problem looks like simple but all the difficulty depends on how the defined the scrambled string

Def : Two Strings are said to be scrambled if we can get another stirng from one string by swaping 0 or more non leaves nodes of same parent node
of binary tree in which string was breaks
if we achieved second string then this strings are said to be scrambled
*/

 
 
#include<bits/stdc++.h>
using namespace std;

// map as dp
unordered_map<string,bool> mp;
bool areScrambled(string a ,string b){
    // base case if two strings are same then they are scrambled so return true
    if(a.compare(b)==0) return 1;
    int n = a.size();
    int m = b.size();

    // if size of strings is different then return false
    if(n!=m) return 0;

    // not understanded this case may be string size gos negative both strings contains only one different chars
    if(n<=1) return 0;

// create key
    string key = a+" "+b;
    // return if this key is allready calculated
    if(mp.find(key)!=mp.end()) return mp[key];
    bool f = 0;
    
    // a=x+y
    // b=u+v

    // breaks the strings in two part and pass the recution
    for(int i=1;i<=n-1;i++){
        // Not Swapped condition
        bool notSwapped = areScrambled(a.substr(0,i),b.substr(0,i)) && areScrambled(a.substr(i),b.substr(i));
        // swapped condition
        bool swapped    = areScrambled(a.substr(0,i),b.substr(m-i))   && areScrambled(a.substr(i),b.substr(0,m-i));

        // out of this any can gives true result then return from that
        if(swapped || notSwapped){
            f=1;
            break;
        }
    }
    // store the result in map
     return mp[key] = f;
}
           
int main(){
      f();
  return 0;
}