// https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1#
// Split a Circular Linked List into two halves

#include<bits/stdc++.h>
using namespace std;
       
struct Node
{
    int data;
    struct Node *next;
};

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // find middle of ll
    Node * slow=head;
    Node* fast=head->next;
    while(fast!=head and fast->next!=head){
        slow=slow->next;
        fast=fast->next->next;
    }
    // breaking at middle and seting to head;
    *head1_ref=head;
    *head2_ref=slow->next;
    slow->next= *head1_ref;
    Node * curr=*head2_ref;
    // traversing send list
    while(curr->next!= head){
        curr=curr->next;
    }
    curr->next=*head2_ref;

}
int main(){
          
  return 0;
}