// Segregate even and odd nodes in a Link List
// https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1

// algo;
// create  4 pointer and then magege separatlye and attach finaly
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
class Solution{
public:
    Node* divide(int N, Node *head){
        Node* even=NULL;
        Node* odd=NULL;
        Node* e=NULL;
        Node* o=NULL;
        while(head!=NULL){
            if(!(head->data&1)){
            if(even==NULL){
                even=head;
                e=head;
            }
            else{
                e->next=head;
                e=e->next;
            }
            }
            else{
                if(odd==NULL){
                    odd=head;
                    o=head;
                }
                else{
                    o->next=head;
                    o=o->next;
                }
            }
            head=head->next;
        }
        if(e) e->next=odd;
        if(o) o->next=NULL;
        
        if(even) return even;
        return odd;
    }
};
           
int main(){
          
  return 0;
}