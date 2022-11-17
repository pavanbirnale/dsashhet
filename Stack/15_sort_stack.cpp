// same as reverse of stack buty only condition of if and else is added in insertatbottom fuction
// if stack is empty then push x
// if stck.top< x then push x
// else top is gtreeter then pop top untill top<x condition reaches
// after that push the poped elment that poped from else block


#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int x)
{
    if (st.empty())
    {
        st.push(x);
        return;
    }
    if(st.top()<x){
       st.push(x);
    }
    else{
    int a = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(a);
    }
}

void stackrev(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int a = st.top();
    st.pop();
    stackrev(st);
    insertAtBottom(st, a);
}
stack<int> revstack(stack<int> s1)
{
    stackrev(s1);
    return s1;
}

int main()
{
    stack<int> st, ref;
    st.push(3);
    st.push(5);
    st.push(1);
    st.push(4);
    st.push(2);
    ref = st;
    while (!ref.empty())
    {
        cout << ref.top() << " ";
        ref.pop();
    }
    cout << "\n";
    st = revstack(st);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}