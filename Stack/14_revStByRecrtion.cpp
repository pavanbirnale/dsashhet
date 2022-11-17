// Reverse a stack using recursion
// https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/

// here we can reverse a stck with help of calaing stack
// first we send stact into reverse recursive function
//  while returning we call another function that aslo called recursively and get stack  empty
//  aftrer become stack empty pushed the new elment and then also push old inserted elments
#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int x)
{
    if (st.empty())
    {
        st.push(x);
        return;
    }
    int a = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(a);
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
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
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