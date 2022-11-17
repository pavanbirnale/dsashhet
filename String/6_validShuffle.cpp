// Write a Program to check whether a string is a valid shuffle of two strings or not

/*
Algo:
1.If lenght is not same
2.ckeck For lenght and charecters of result string
*/
#include<bits/stdc++.h>
using namespace std;

bool isValidShuffle(string s1, string s2, string result){
    if(s1.length()+s2.length()!=result.length()) return 0;
    int i=0,j=0,k=0;
    while(k<result.length()){
        if(i<s1.length() && s1[i]==result[k]) i++;
        else if(j<s2.length()&&s2[j]==result[k])j++;
        else{ break;}
        k++;
    }
    if(i<s1.length() || j<s2.length()) return 0;
    return 1;
}
           
int main(){
          cout<<isValidShuffle("xy","12","y12y");
  return 0;
}