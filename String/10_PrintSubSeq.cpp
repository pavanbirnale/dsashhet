#include<bits/stdc++.h>
#include<string.h>
using namespace std;


void printSubSEq(string res,int start,int end,string str){
    if(start==end){
        cout<<res<<"\n";
    }
    else{
        // ek bar add karnay ek bar nahi each charecter ko
        printSubSEq(res,start+1,end,str);
        res+=str[start];
        printSubSEq(res,start+1,end,str);
    }

 
}
           
int main(){
    string a="abc";
    printSubSEq("",0,a.length(),a); 
  return 0;
}