// 767. Reorganize String

// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

// Return any possible rearrangement of s or return "" if not possible.


/*
Algo : 
1.count the frequence of each charecter of string and store it into map;
2.push all the stored item to priority queue
after that get top item of pq and append its char to ans string
and decresse its freq

then use while loop untill pq becomes empty
get top of pq and append its char to ans;
pop it from pq 
decress its freq and repalce it with block
before that push prev block to 
*/
#include<bits/stdc++.h>
using namespace std;

string reorganize(string s){
    int size=s.size();
    // create map
    unordered_map<char,int>mp(26);
    // push all chars to map
    for(int i=0;i<size;i++){
        mp[s[i]]++;
    }
    // create max heap
    priority_queue<pair<int,char>>pq;

// push all map elemnt to heap
    for(auto itr :mp){
        pair<int,char> curr={itr.second,itr.first};
        pq.push(curr);
    }
    // base case to initalise ans and block temp
    string ans="";
    pair<int,char> block=pq.top();
    pq.pop();

    ans+=block.second;
    // decress freq of chars each time
    block.first--;

    while(!pq.empty()){
        // get pq top element to temp
        pair<int,char> temp=pq.top();
        // add temps char to ans
        ans+=temp.second;
        // pop top
        pq.pop();

// imp step push element to priority queue if its freq is greater than zero
        if(block.first>0){
            pq.push(block);
        }
        block=temp;
        block.first--;
    }
    // is any elemnt is remaining in block and pq becomes empty then we have to return empty string
    if(block.first>0){
        return "\n";
    }
    return ans;
}
           
int main(){
    string s="aaab";
cout<<reorganize(s);
  return 0;
}