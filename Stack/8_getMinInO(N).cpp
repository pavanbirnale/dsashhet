// Design a Stack that supports getMin() in O(1) time and O(1) extra space.
// https://practice.geeksforgeeks.org/problems/special-stack/1
/*
Three Approches:
1. TC:O(N^2) SC: O(N)
2. TC:O(1) SC: O(N)
3. TC:O(1) SC: O(1)

2nd Approch: (better)
Use another stack to maintain min elements
and iterrate over one stack if min come then push it to stack the problem of going back to prev min 
is overcome by another stack

3rd Approch: (best)
here when the min value is come then we not the value to the stack but push its increpted value and when the condition is
reched while poping that st.top<min then min go to its pre min by decreptin it
*/
#include<bits/stdc++.h>
using namespace std;

int mi=INT_MAX;


void push(stack<int>st,int a){
    // if stack is empty then push elemnt to stack directly
    if(st.empty())
    {
        mi=a;
        st.push(a);
    }
    // if st is not empty then check of eack upcoming elment that if it is less that min elm or not 
    // if it is true then push increpted valu to stack and change min to a;
    // then push that  increpted value if  if block is false then push that value directly 
    else{
        int x=a;
        if(mi>a){
            // due to these increption x in stack must be lesser than 
            x=2*x-mi;
            mi=a;
        }
        st.push(x);
    }
}
void pop(stack<int> st){
    
    int zx_1=st.top();
    // while poping if top is greeter than min then pop it directly
    if(zx_1>=mi){
        st.pop();
    }
    // if not the decrept min and pop the increpted value from stack
    // if value in stack that mence zx_1 is smaller that mi then zx_1 must be increpted value and our next min will change
    else{
        // above we added 2x  so while decrepting 
        /*
        increption of value ->
        elemThatHaveToPush = 2 *  givenElem - prevMin;
               x           = 2 *      x     -   mi

        decreption of value ->
            nextMin        = 2 *  currMin -stack.top();
        */ 
        mi=2*mi-zx_1;
        st.pop();
    }
}

int getMin(stack<int> st){
   return mi; 
}

           
int main(){
          
  return 0;
}