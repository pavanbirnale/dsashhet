






// In dp similar problem present which only return count












// Print all palindromic partitions of a string
// https://practice.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1/#
/*

input : geeks

output : 
g e e k s
g ee k s


here in this problem what we ahve to do is that divied the string into parts such that all parts are palindrome
so by this way print all the possible partitions

*/
#include<bits/stdc++.h>
using namespace std;

// global ans vector
vector<vector<string>> ans;

// fi=unction that checks whether the string is palindrome or not
bool isPalindrome(string str){
    int lo = 0;
    int hi = str.size()-1;

    while(lo<hi){
        if(str[lo]!=str[hi]) return 0;
        lo++;
        hi--;
    }
    return 1;
}

// main function
void palindromicUtil(string str, vector<string> currpart){

    // when size of string becomae zero then push currpart vector to ans and return back
    if(str.size() == 0) {
        ans.push_back(currpart);
        return;
    }

    // take all parts of stings
    for(int i=0;i<str.size();i++){
        string prefix = str.substr(0,i+1);
        string rest = str.substr(i+1);
        if(isPalindrome(prefix)){
            currpart.push_back(prefix);
            palindromicUtil(rest,currpart);
            currpart.pop_back();
        }
    }
}
vector<vector<string>> palindroicPartitions(string str){
vector<string> currpart;
palindromicUtil(str,currpart);
return ans;
}

// function to print the ans 
void printAns(){
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main(){
    palindroicPartitions("geeks");
    printAns();
  return 0;
}