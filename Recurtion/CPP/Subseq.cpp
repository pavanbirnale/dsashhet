// Print all subsequences of a string by recurtion
#include<bits/stdc++.h>
using namespace std;

vector<string> getSubseq(string str){
    //  base case is very important here we push empty string which then combine with next chars which are store at first 
    if(str.length()==0){
        vector<string> baseRes={};
        baseRes.push_back("");
        return baseRes;
    }
    char first = str[0];
    string newStr = str.substr(1);
    vector<string> rRes = getSubseq(newStr);
    vector<string> newRes ={};
    for(int itr=0;itr<rRes.size();itr++){
        newRes.push_back(rRes[itr]);
    }
    for(int itr=0;itr<rRes.size();itr++){
        string neww =first+rRes[itr];
        newRes.push_back(neww);
    }
    return newRes;
}  

int main(){
    string str="abc";
    cout<<str;
    vector<string> arr=getSubseq(str);
    for(auto itr : arr){
        cout<<itr<<" ";
}
}