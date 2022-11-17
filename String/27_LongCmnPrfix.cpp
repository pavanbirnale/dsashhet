// Longest Common Prefix
#include<bits/stdc++.h>
using namespace std;

string longConPre(vector<string> str){
    if(str.size()==0) return "";
    int MainAns=INT_MAX;
    string c=str[0];
    for(int i=1;i<str.size();i++ ){
        int j=0;
        int k=0;
        int ans=0;
        while(j<c.size() && k<str[i].size()){
            if(c[j]==str[i][k]) ans++;
            else break;
            j++;
            k++;
        }
        MainAns=min(MainAns,ans);
    }
    return c.substr(0,MainAns);
}
int main(){
vector<string> vect={"flower","flow","flight"};
cout<<longConPre(vect);
    return 0;
}