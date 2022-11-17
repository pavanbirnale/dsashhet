// https://leetcode.com/problems/middle-of-the-linked-list/submissions/
// 876. Middle of the Linked List

/*
Approch : 1
Two aproches !st is of O(n) TC and traversing LL two times
Algo:
1.Find length of LL of traversing in while loop
2.In another while loop Traverser untill N/2 and return curr pointer
See leetcode solution

Approch : 2 Rare and Tortose tratergy
1. Initialkise two poiner Show and fast
2. move the solw pointer by one step and fast by two step
3. when fast reach at end at that time solw is at middle of LL
and 
4.these aproch is here
*/

#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
   Node* middle(struct Node* head){
       Node* slow = head;
       Node *fast = head;
       while (fast!=NULL || fast->next!=NULL){
           slow=slow->next;
           fast=fast->next->next;
       }
       return slow;
       
   }

           
int main(){
          
  return 0;
}