//Find the starting point of the loop. 
// https://www.geeksforgeeks.org/find-first-node-of-loop-in-a-linked-list/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};
class solution{
    struct Node * FirstNode(struct Node* head){
        Node* lo=head;
        Node* hi=head;
        while(hi!=NULL and hi->next !=NULL){
            lo=lo->next;
            hi=hi->next->next;
            if(lo==hi){
                break;
            }
        }
        if(lo==hi){
            lo=head;
            while(lo->next!=hi->next){
                lo=lo->next;
            }
            
        }
        return lo->next;
    }
};
           
int main(){
          
  return 0;
}
