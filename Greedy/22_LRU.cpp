// Program for Least Recently Used (LRU) Page Replacement algorithm

// similar problem of LRU we have seen in stacks and queue basicaly in queue
/*
So what is LRU ?
It is an algorithm to used in pagination in web etc
here we have gives some data and a cap-asity of memory untill we exceed memory we can fill tha dat but when we reach to full memory condition then 
we have to removes lest recently used data from memory and then insert new data.


in our queue LRU implementation problem we have given two types of quiry set qurey and get queiry
set can set data in memort and get can give data and set the data as resenlty used


similar approch we use here

for proceeding further we need two data structure  list and map

list for managing memory and map for seraching the datab in memory as w store address of data of list in map;
so when we set or get data it can be easly mannage by using list 
*/
#include<bits/stdc++.h>
using namespace std;

int LRUCache(int pages[],int n,int c){

    list<int> ll;
    unordered_map<int,list<int>::iterator> mp;

    int pgFault=0;
    for(int i=0;i<n;i++){
        // if data find then erase it from ll ans mp will updates so no need to handdle mp
        if(mp.find(pages[i])!=mp.end()){
            ll.erase(mp[pages[i]]);
        }
        else{
            // if data not found then incress page fault and check size of list if it reach to capasity then erase lesast recently used data
            pgFault++;
            // imppppppp main logic is here
            if(ll.size()==c){
                mp.erase(ll.back());
                ll.pop_back();
            }
        }
        // in both the condition update data in list
        ll.push_front(pages[i]);
        mp[pages[i]]=ll.begin();
    }
    return pgFault;
}
           
int main(){
    int pages []= {5, 0, 1, 3, 2, 4, 1, 0, 5};
   cout<<LRUCache(pages,9,4);
  return 0;
}