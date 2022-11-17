#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *prev;
    Node *next;
    Node(int x){
        data=x;
        next=prev=nullptr;
    }
};
Node *dummy = new Node(-1);
Node *head =dummy;
Node *mid =dummy;
int cnt=0;

void push(int x){
    Node* newNode = new Node(x);
    newNode->prev = nullptr;
    newNode->next = head;
    head->prev = newNode;
    head=newNode;
    cnt++;
    if(cnt==1) mid=newNode;
    else if( cnt%2==0)mid=mid->prev;
}

int pop(){
    if(cnt==0) {
        cout<<"stack is empty";
        return -1;}
    Node *temp=head;
    head=head->next;
    if(head) head->prev=nullptr;
    temp->next=nullptr;
    cnt--;
    int d=temp->data;
    delete(temp);
    if(cnt%2==1){
        mid=mid->next;
    }
    return d;
}

int middle(){
    if(cnt==0) return -1;
    return mid->data;
}

int delmid(){
    if(cnt==1){
        pop();
    }
    if(cnt==2){

    }
    Node *temp=mid;
    mid=mid->next;
    temp->prev->next=mid;
    mid->prev=temp->prev;
    int d=temp->data;
    delete(temp);
    return d;
}
// 1 2 3 4
void print(Node *head){
    while(head->next){
        cout<<head->data<<" ";
        head=head->next;
    }
}

           
int main(){
          push(1);
          push(2);
          push(3);
          push(4);
          push(5);
          push(6);
          print(head);
          cout<<"\n"<<delmid()<<" ";
          cout<<"\n"<<delmid()<<" ";
          cout<<"\n"<<delmid()<<" ";
          cout<<"\n"<<delmid()<<" ";
          print(head);
          cout<<"\n"<<middle()<<"\n";
  return 0;
}