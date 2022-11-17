// Reverse a linked list
// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1#
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

           

class Solution
{
    public:
    struct Node* reverseListRecursive(struct Node *head)
    {
 
        if(!head || !head->next){
            return head;
        }
        // recursivley call the function
        struct Node* rest =reverseListRecursive(head->next);
        // set self next of next to self
        head->next->next=head;
        // set next of head to null 
        head->next=NULL;
        return rest;
        
    }
    struct Node* reverseListIterative(struct Node *head)
    {
      struct Node *curr,*prev,*next;
      if(head==NULL || head->next==NULL) return head;
      prev=NULL;
      curr=head;
      while(curr!=NULL){
        //these is important  chenge next here only///
          next=curr->next;
          curr->next=prev;
          prev=curr;
          curr=next;
      }
      return prev;
    }
    
};
int main(){
          
  return 0;
}