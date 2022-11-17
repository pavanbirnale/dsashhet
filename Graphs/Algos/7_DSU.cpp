// Disjoint Set Union
// It is a Data stucture
// Detect Cycle in undirected weighted graph by using Disjoint set union

//  the algorithm has amoterize time complexit O(alpha(N));

 /*
 Code has Three functions:
 1. make : make new independent node
 2. find : return the parent of the node
 3. union : takes two arguments and attach the roots of both nodes







 for optimization We do two steps ahead :
 1. union by size or rank
 2. path comprestion


 */
 
#include<bits/stdc++.h>
using namespace std;

// here initializing parent arr and size array
vector<int> par;
vector<int> size;

// make fuction that makes individual components
void make(int v){
     par[v] = v;
     size[v] = 1;
}

// this function returns the parent of v node
int find(int v){
    if(par[v]==v) return v;
    // path comprestion : rather than only returning change the node to parent
    return par[v] = find(par[v]);
}

void Union(int a,int b){
    int parOfa = find(a);
    int parOfb = find(b);

    if(parOfa != parOfb){

        // union by size
        if(size[parOfa]<size[parOfb]) swap(parOfa,parOfb);
        par[parOfb] = parOfa;
        size[parOfa] += size[parOfb];
    }
}
           
int main(){
  itn v,k;
  cin>>v>>k;

  par.resize(v+1);
  size.resize(v+1);

  for(int i=1;i<=v;i++){
      make(i);
  }
  while(k--){
      cin>>u>>v;
      Union(u,v);
  }
  int connectedCount = 0;
  for(int i=1;i<=v;i++){
      if(find(i)==i) connectedCount++;
  }
  cout<<connectedCount<<endl;
  return 0;
}