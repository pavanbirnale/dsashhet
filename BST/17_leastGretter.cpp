/*
Attention Darshan:
Gretter / Gretest element to the right has varity of problems
1.next gretter element to the right      =>upcoming firs getter elemnt from curr element
2.next least getter element to the right =>next exactly getter element to the right means smallest element in right side which is gretter than curr
3.grettest elemnt to the right           =>leetcode higest element to the right
*/

// DSA sheet has problem which goes under 2nd type of above

// Also next getter elemt sol present in pepcoding folder

// Replace every element with the least greater element on its right

// categary 1 solution (pepcoding)

#include<bits/stdc++.h>
using namespace std;

vector<int> nextGretterElem(vector<int> v){
    int s=v.size();
    vector<int> ans;
    stack<int> st;
    ans.insert(ans.begin(),-1);
    st.push(v[s-1]);
    for(int i=s-2;i>=0;i--){
        while(!st.empty() and v[i]>=st.top()){
            st.pop();
        }
        if(st.empty()){
            ans.insert(ans.begin(),-1);
        }
        else if(st.top()>v[i]){
            ans.insert(ans.begin(),st.top());
        }
        st.push(v[i]);
    }
    return ans;
}
           
int main(){
          
  return 0;
}