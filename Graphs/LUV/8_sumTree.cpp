// Calculate and print the sum of each subTree || sumTree

// Along with that calculate even value node in each subtree



/*





This code is not much important as most of the time we have given Tree as TreeNode not a graph
and this code is for Tree which is given as a graph not for Tree given by TreeNodess

Also works for that graph only which has vertex from 0 to n-1 range.




*/








#include<bits/stdc++.h> 
using namespace std;


vector<int> sumTree;
vector<int> evenCount;

void dfs(int vrtx, int par){

    if(vrtx % 2 == 0) evenCount[vrtx]++;
    sumTree += vrtx;
    for(auto nbr : Graph[vrtx]){
        if(nbr!=par){
            dfs(nbr,vrtx);
            sumTree[vrtx] +=sumTree[nbr];
            evenCount[vrtx] +=evenCount[nbr];
        }
    }
}

int main(){
    dfs(1,0);
    for(int i=1;i<=n;i++){
        cout<<sumTree[i]<<" "<<evenCount[i]<<endl;
    }
    return 0;
}