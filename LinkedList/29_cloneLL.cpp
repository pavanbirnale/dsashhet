// Clone a linked list with next and random pointer
// https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1#

//  create node function not witten here so program 


// Algorithm:
// 1->2->3->4->5->6
// 1st create clone oof each node like these in 1st while loop
// 1->1->2->2->3->3->4->4->5->5->6->6
// then clone arbitary poinrets of each node
// at last separate both the lists

#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    struct Node *arb;
};

class sol{
    public:
    Node *copyList(Node *head)
    {
       Node* curr=head;
       Node* temp;
       while(curr){
           temp=curr->next;

        //    curr->next=new Node(curr->data);
           curr->next->next=temp;
           curr=temp;
       }
       curr=head;
       while(curr){
         curr->next->arb=curr->arb ? curr->arb->next : curr->arb;
         curr=curr->next->next;
       }

       Node* original=head;
       Node* clone=head->next;
       temp=clone;
       while(original and clone){
           original->next=original->next->next;
           clone->next=clone->next ? clone->next->next : clone->next;
           original=original->next;
           clone=clone->next;
       }
       return temp;
    }


};
           
int main(){
          
  return 0;
}