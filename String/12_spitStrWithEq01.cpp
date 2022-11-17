// Split the Binary string into two substring with equal 0’s and 1’s

#include<iostream>
#include<string>
using namespace std;
int countSubstr(string str){
    int y=0,x=0,c=0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='1') x++;
        else if(str[i]=='0') y++;
        if(x==y) c++;
    }
    if(x!=y) return -1;
    return c;
}

int main(){
    
    cout<<countSubstr("0000000000");
    return 0;
}