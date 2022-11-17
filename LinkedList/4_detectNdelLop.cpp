// Write a program to Delete and delete loop in a linked list.
// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1#

// We also use map for it it is very srate forward
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
    void removeLoop(Node* head)
    {
        // Same as deltecting the loop and break loop when both pointer maches
        Node *lo=head,*hi=head;
        while(lo!=NULL and hi!=NULL and hi->next!=NULL){
            lo=lo->next;
            hi=hi->next->next;
            if(hi==lo){
                break;
            }
        }

        // Corner caes if lo and hi are at head the we use if block
        if(lo==head){
            while(lo!=hi->next){
            hi=hi->next;}
            hi->next=NULL;
        }
        // for all, other conditions
        else if(hi==lo){
            lo=head;
            while(lo->next!=hi->next){
                lo=lo->next;
                hi=hi->next;
            }
            hi->next=NULL;
        }
    }
};;
           
int main(){
          
  return 0;
}