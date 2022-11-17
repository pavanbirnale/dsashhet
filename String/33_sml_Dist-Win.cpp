// Write a program tofind the smallest window that contains all characters of string itself.
// https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1#
#include<bits/stdc++.h>
using namespace std;

           

class Solution{
    public:
    string findSubString(string str)
    {
        // create set for geting distict elemnt in string
        set<char>s;
        for(int i=0;i<str.length();i++){
           s.insert(str[i]); 
        }
        int uc=s.size();
        // create map to mannage count of elments
        unordered_map<char,int> mp;
        int i=0;
        int j=1;
        mp[str[i]]++;
        int mi=INT_MAX;
        int c=0;
        c++;
        while(i<=j and j<str.length()){
            if(c<uc){
                // if count c of elments is less than total distict elemrnt them simply push emnt into map untill count == dist elm
                if(mp[str[j]]==0) c++;
                mp[str[j]]++;
                j++;
            }
            else if(c==uc){
                // if  count become eql them shinks the window and get min length
                mi=min(mi,j-i);
                if(mp[str[i]]==1) c--;
                mp[str[i]]--;
                i++;
            }
            
        }
        // if lst loop end with if condition then for shinking use these while loop
            while(c==uc){
                mi=min(mi,j-i);
                 if(mp[str[i]]==1)c--;
                mp[str[i]]--;
                i++;
            }
        // thes is our adjment of sending string as return because the only needs lenght
        string ans="";
        for(int i=0;i<mi;i++){
            ans+='a';
        }
        return ans;
        
    }
};
int main(){
          
  return 0;
}