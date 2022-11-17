// Intersection Point in Y Shapped Linked Lists
// https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1#

// Approch 1 :-> Like these use map and chechk for poinert of next lists TC=O(M+N) SC: O(N)
// Approch 2 :-> Use pointers only algo:
/*
1. find length of two LL
2. Interate max length ll Upto abs(l1-l2)
3. Now both LL are at same level to iterte both chech for same targeting pointer
5 and return data of target pointer
*/
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
           
int intersectPoint(Node* head1, Node* head2)
{
   unordered_map<Node*,int> mp;
   while(head1!=NULL){
       mp[head1]=1;
       head1=head1->next;
   }
   while(head2!=NULL){
       if(mp[head2]){
           return head2->data;
       };
       head2=head2->next;
   }
   return NULL;
}
    
    int main(){
          
  return 0;
}
