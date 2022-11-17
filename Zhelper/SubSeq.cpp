// Generate all Subsequences of string

// TC : O(2^n);
// SC : O(n*2^n);

// There are 2^n subseq of n size string

/* There are Two Approches to find the Subseq of string
   1). BackTracking (Recursive)
   2). Power Set (Iterative)  : Powerset of set/arr A is set of all subset of A
*/

#include<bits/stdc++.h>
using namespace std;

// 1).BackTracking : 

void Subseq(string str,int i,vector<string>& ans ,string curr){
    ans.push_back(curr);
    for(int j=i;j<str.size();j++){
        curr+=str[j];
        Subseq(str,j+1,ans,curr);
        curr.pop_back();
    }
}










// 2).Power set : https://www.geeksforgeeks.org/power-set/
// short form : pss => power set size

vector<string> PowerSet(string str){
    int n = str.size();
    vector<string> ans;
    unsigned int pss = pow(2,n);
    int c, j;
    for(c = 0; c < pss; c++){
        string temp = "";
        for(j = 0; j < n; j++){
            if(c & (1 << j))
                temp+=str[j];
        }
        ans.push_back(temp);
    }
    sort(ans.begin(),ans.end());
    return ans;
}
















int main(){
    // BackTracking :
    string str = "ABC";
    vector<string> ans;
    string curr;
    Subseq(str,0,ans,curr);


    // power set :
    // vector<vector<int>> ans = PowerSet(arr);
    for(auto row : ans){
        for(auto i : row){
            cout<<i<<" ";
        }
        cout<<endl;
    }
  return 0;
}



