// https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1#
// Reverse a Doubly Linked list.

// Aldgo:
// 1. rev first and last node indivedualy and then revares remaining list

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};


Node* reverseDLL(Node * head)
{
     if(head==NULL or head->next==NULL) return head;

    Node * curr=head;
    // Reverse 1st node
    curr->prev=curr->next;
    curr->next=NULL;
    curr=curr->prev;
    // reversr remaining
    while(curr->next!=NULL){
        Node *temp=curr->next;
        curr->next=curr->prev;
        curr->prev=temp;
        curr=curr->prev;
    }
    // reverse last node
    curr->next=curr->prev;
    curr->prev=NULL;
    return curr;
}
           
int main(){
          
  return 0;
}