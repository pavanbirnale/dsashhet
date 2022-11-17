#include<bits/stdc++.h>
using namespace std;

void insert_at_bottom(stack<int> &st,int val){
    if(st.empty()){
        st.push(val);
        return;
    }
    int x=st.top();
    st.pop();
    insert_at_bottom(st,val);
    st.push(x);
}
void dis(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<"\n";
        st.pop();
    }
}
int main(){
    stack<int> st;
    st.push(9);
    st.push(8);
    st.push(7);
    st.push(6);
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    dis(st);
    cout<<"----------------------"<<"\n";
    insert_at_bottom(st,10);
    dis(st);
  return 0;
}