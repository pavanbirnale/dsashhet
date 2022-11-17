// Given a sorted Dictionary of an Alien Language, find order of characters

/*
In ths Question we have given dictionary of word and we have to return string of words in alianabetical order
*/

/*
Algorithm :
First of all this problem is based on topological sort so. we do normal topological sort by using dfs 
but important thing here is that how to construct the graph from the dict

so for that each time we compare two word and is there letters are different then push that letters to graph and 
break the loop it is important
*/
 
 
#include<bits/stdc++.h>
using namespace std;
           
class Solution{
    public:
    vector<vector<int>> graph;
    vector<int> vis;
    string ans = "";
    
    void dfs(int par){
        vis[par] = 1;
        for(auto nbr : graph[par]){
            if(!vis[nbr]){
                dfs(nbr);
            }
        }
        char ch = par+'a';
        ans=ch+ans;
    }
    string findOrder(string dict[], int N, int k) {
        int n = N;
        graph.resize(k);
        vis.resize(k,0);
        for(int i=0;i<n-1;i++){
            string w1 = dict[i];
            string w2 = dict[i+1];
            
            for(int j=0;j<min(w1.size(),w2.size());j++){
                if(w1[j]!=w2[j]){
                    graph[w1[j]-'a'].push_back(w2[j]-'a');
                    break;
                }
            }
        }
        for(int i=0;i<k;i++){
            if(!vis[i]) dfs(i);
        }
        // cout<<ans<<endl;
        return ans;
    }
           
int main(){
      f();
  return 0;
}