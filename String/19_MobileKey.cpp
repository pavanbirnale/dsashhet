// Convert a Sentence into its equivalent mobile numeric keypad sequence.
#include<bits/stdc++.h>
using namespace std;

string mobileKeys(string str){

    string keys[] ={"2","22","222","3","33","333","4","44","444","5","55","555","6","66","666","7","77","777","7777","8","88","888","9","99","999","9999"};
    string ans="";
    for(int i=0;i<str.size();i++){
        if(str[i]==' ') ans+="0";
        else{
            ans+=keys[str[i]-'A'];
        }
    }
    return ans;
}
           
int main(){
     cout<<mobileKeys("GEEKSFORGEEKS");
  return 0;
}