// Check if Linked List is Palindrome
// https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1#

/*
Algo:
1. go to middle of linked list and then
2. reverse ll from middle to end then prev is pointing to miidle element and
3. set fast to head and prev to middle and move forward and check their data is same or not
*/
#include<bits/stdc++.h>
using namespace std;
       
struct Node
{
    int data;
    struct Node *next;
};

class Solution{
  public:
    bool isPalindrome(Node *head)
    {
        // find middle of ll
        Node *slow=head;
        Node* fast=head;
        while(fast!=NULL and fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        //Reverse LL from middle
        Node *curr=slow;
        Node *prev=NULL;
        Node *next;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        fast=head;
        // check for Padilndrome
        while(prev!=NULL){
            if(prev->data!=fast->data){
                return false;
            }
            fast=fast->next;
            prev=prev->next;
        }
        return true;
    }
};

int main(){
    return 0;
}