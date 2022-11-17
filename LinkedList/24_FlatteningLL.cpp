// Flatten a Linked List (VIMP)
// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;
};


// smae algo like merge sort of linked list
// calling merge function recursivley
Node* merge(Node* first,Node* second){

// if node of 1st LL is NULL then return 2nd node
    if(!first) return second;

// if node of 2nd LL is Null then return 1st node
    if(!second) return first;
    
    Node* ans;

// if data of first node is less then go with 1st and call to 1st next recursivly 
    if(first->data<second->data){
        ans=first;
        ans->bottom=merge(first->bottom,second);
    }

// else second
    else{
        ans=second;
        ans->bottom=merge(first,second->bottom);
    }
// each time next of each node will be NULL
    ans->next=NULL;
    return ans;
}

// main function
Node *flatten(Node *root)
{
   if(!root || !(root->next)){
       return root;
   }
   return merge(root,flatten(root->next));
}

           
int main(){
          
  return 0;
}