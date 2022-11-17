// print keypad sequence
#include<bits/stdc++.h>
using namespace std;

string codes[] = {".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};

void PrintString(string str,string ans){
    if(str.size()==0){
        cout<<ans<<" ";
        return;
    }
    char first = str[0];
    string rest = str.substr(1);

    string options = codes[first-'0'];

    for(int i=0;i<options.size();i++){
        char currChar = options[i];
        PrintString(rest,ans+currChar);
    }
}
int main(){
    string str;
    cin>>str;
    PrintString(str,"");
}