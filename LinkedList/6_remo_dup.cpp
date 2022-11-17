// https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1#
// Remove duplicate element from sorted Linked List
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
           
Node *removeDuplicates(Node *head)
{

    if(head==NULL || head->next==NULL ) return ;
  struct  Node * curr=head->next,*prev=head;
    while(curr!=NULL){
        if(curr->data==prev->data){
            Node *temp=curr;
            curr=curr->next;
            prev->next=curr;
            delete(temp);
        }
        else{
            prev=curr;
            curr=curr->next;
            
        }
    }
    }
    
    int main(){
          
  return 0;
}