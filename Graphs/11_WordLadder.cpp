// World Ladder

/*
There are two ways for Solving the problem
1. Gives TLE : after Reading the que it is clear that we can directly create map if somehow knows if two string are differs by only one char
so for that we create a function that tell us above result in o(n) time
after that we simply do BFS
but, due to the checking operation this approach gives tle

2.Accepted :
Another approach is that rahter that createing graph create set from world list and by using all 26 chars on each position try to 
get new word word least to reach to words end word
*/

 
        
// 1.TLE Approach : 

#include<bits/stdc++.h>
using namespace std;

unordered_map<string,vector<string>> graph;
unordered_map<string,int> vis;
unordered_map<string,int> lev;
    

// This Function returns where the strings only diffres in one char
bool isOneDifferOnly(string a,string b){
    if(a.size()!=b.size()) return 0;
    int diffC = 0;
    for(int i=0;i<a.size();i++ ){
        if(a[i]!=b[i]) diffC++;
        if(diffC>1) return 0;
    }
    return 1;
}

// Normal Bfs
void bfs(string beginWord,string endW,vector<string> wl){
    queue<string> q;
    q.push(beginWord);
    
    vis[beginWord] = 1;
    lev[beginWord] = 1;
    
    while(!q.empty()){
        string par = q.front();
        q.pop();
        for(auto nbr : graph[par]){
            if(!vis[nbr]){
                q.push(nbr);
                vis[nbr] = 1;
                lev[nbr] = lev[par] + 1;
            }
            if(lev[endW]!=0) return;
        }
    }
}
// Main Function
int ladderLength(string beginWord, string endWord, vector<string>& wl) {
    bool f=0;
    // for base case and also push beginword separately in map as it is not present in wl
    for(int j=0;j<wl.size();j++){
            if(isOneDifferOnly(beginWord,wl[j])){
            graph[beginWord].push_back(wl[j]);
        }
        if(endWord==wl[j]){
            f=1;
        }
    }
    // if end word is not present in word list then also return 
    if(!f) return 0;

    for(int i=0;i<wl.size();i++){
        if(i!=j && isOneDifferOnly(wl[i],wl[j])){
            graph[wl[i]].push_back(wl[j]);
        }
        
    } 
    // creating graph
    for(int i=0;i<wl.size();i++){
        for(int j=0;j<wl.size();j++){
            if(i!=j && isOneDifferOnly(wl[i],wl[j])){
                graph[wl[i]].push_back(wl[j]);
            }
        }
    }
    
    
    // for(auto itr : graph){
    //     cout<<itr.first<<" --> ";
    //     for(auto i : itr.second){
    //         cout<<i<<" ";
    //     }
    //     cout<<endl;
    // }

    bfs(beginWord,endWord,wl);
    return lev[endWord];
}
int main(){
  return 0;
}










// Approach : 2 => Accepted

#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int> lev;

void bfs(string beginWord,stirng endWord,vector<stirng> wl){
    set<string> st(wl.begin(),wl.end());

    queue<string> q;
    q.push(beginWord);
    lev[beginWord] = 1;

    while(!q.empty()){
        string par = q.front();
        q.pop();
        for(int i=0;i<par.size();i++){
            for(char j='a';j<='z';j++){
                string temp = par;
                temp[i]=j;
                if(temp.compare(par)==0){
                    return;
                }
                if(temp.compare(endW)==0){
                    lev[temp] = lev[par] + 1;
                    return;
                }
                else if(st.find(temp)!=st.end()){
                    st.erase(temp);
                    q.push(temp);
                    lev[temp] = lev[par] + 1;
                }
            }
        }
    }
}

int ladderLength(string beginWord, string endWord, vector<string>& wl) {
    bfs(beginWord,endWord,wl);
    return lev[endWord];
}

int main(){
      f();
  return 0;
}