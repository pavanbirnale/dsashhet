#include<bits/stdc++.h>
using namespace std;

int countAndRecv(string str){
    if(str.length()&1) return -1;
    stack<char> st;
    int c1=0,c2=0;
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        if(ch=='{'){
            st.push(ch);
            c1++;
        }
        else if(ch=='}' and !st.empty() and st.top()=='{'){
            st.pop();
            c1--;
        }
        else{
            c2++;
        }
    }
        if(c1&1) c1=(c1/2)+1;
        else c1=c1/2;
        if(c2&1) c2=(c2/2)+1;
        else c2=c2/2;
    
        return c1+c2;
}
           
int main(){
    cout<<countAndRecv("}{{}}{{{");
  return 0;
}