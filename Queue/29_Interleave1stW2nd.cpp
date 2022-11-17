// Interleave the first half of the queue with second half
// https://www.geeksforgeeks.org/interleave-first-half-queue-second-half/
#include<bits/stdc++.h>
using namespace std;

// initial que and stack
// 1 2 3 4 5 6
// 
queue<int> interleave(queue<int> q){
int n=q.size();
int i=n/2;
stack<int> st;

while(i--){
st.push(q.front());
q.pop();
}
// now que is
// 4 5 6

// n stack is 
// 3
// 2 
// 1
while(!st.empty()){
  q.push(st.top());
  st.pop();
}
// now que is
// 4 5 6 3 2 1

// n stack is 
// empty();
i=n/2;
while(i--){
  q.push(q.front());
  q.pop();
}
// now que is
// 3 2 1 4 5 6

// n stack is 
// empty()
i=n/2;
while(i--){
  st.push(q.front());
  q.pop();
}
// now que is
// 4 5 6

// n stack is 
// 1
// 2
// 3
while(!st.empty()){
  q.push(st.top());
  q.push(q.front());
  st.pop();
  q.pop();
}
// then iterating pver que and stack and returning ans
return q;
// initial : 1 2 3 4 5 6
// final   : 1 4 2 5 3 6
}
           
int main(){
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);
  q.push(6);
  q=interleave(q);
  while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
  }
  return 0;
}

