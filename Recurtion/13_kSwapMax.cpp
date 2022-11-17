// Largest number in K swaps 

// see gfg question ide where pepcoding solution not work


// here we have a string and have to find maximum number string by performin k swaps

#include<bits/stdc++.h>
using namespace std;


  string swapChars(string str,int i,int j){
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        return str;
    }

void FindMaxNumUtil(int idx,string str,int k,string &mx){

    // if swap count get zero then return back
    if(k==0){
        return;
    }

// initialize maxChar as str of idx
    char maxChar=str[idx];

// check for greater char
    for(int i=idx;i<str.size();i++){
        if(maxChar<str[i]){
            maxChar = str[i];
        }
    }
    if(maxChar != str[idx]){
        k--;
    }

// call from here
    for( int i= idx;i<str.size();i++){
        if(maxChar==str[i]){
            string swapped = swapChars(str,i,idx);
            if(swapped.compare(mx)>0) mx=swapped;
            FindMaxNumUtil(idx+1,swapped,k,mx);
        }
    }
}
string FindMaxNum(string str,int k){
    string mx = str;
    FindMaxNumUtil(0,str,k,mx);
    return mx;
}

int main(){
    cout<<FindMaxNum("1234567",4);
  return 0;
}