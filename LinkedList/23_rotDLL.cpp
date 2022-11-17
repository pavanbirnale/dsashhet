// https://www.geeksforgeeks.org/rotate-doubly-linked-list-n-nodes/
// Rotate DoublyLinked list by N nodes.

#include <bits/stdc++.h>
using namespace std;

class dubblylinkedlistnode
{
public:
    char data;
    dubblylinkedlistnode *prev;
    dubblylinkedlistnode *next;
};
class dubblylinkedList
{
public:
    dubblylinkedlistnode *head = NULL;

    dubblylinkedlistnode *createNode(char d)
    {
        dubblylinkedlistnode *newNode = new dubblylinkedlistnode();
        newNode->data = d;
        newNode->next = NULL;
        newNode->prev = NULL;
        return newNode;
    }
    void appendNode(char x)
    {
        dubblylinkedlistnode *ptr = head;
        dubblylinkedlistnode *temp = createNode(x);
        if (ptr == NULL)
        {
            head = temp;
            return;
        }
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->prev = ptr;
        ptr = temp;
    }

   dubblylinkedlistnode * Rotate(int k){
 
       dubblylinkedlistnode* headmain=head;
       dubblylinkedlistnode* prev;
       while(k--){
           prev=head;
           head=head->next;
       }
       prev->next=NULL;
       head->prev=NULL;
       dubblylinkedlistnode* curr= head;
       while(curr->next!=NULL){
           curr=curr->next;
       }
       curr->next=headmain;
       return head;
   }
    void print()
    {
        dubblylinkedlistnode *curr = head;
        while (curr != NULL)
        {
            cout << curr->data << "-->";
            curr = curr->next;
        }
    }
};

int main()
{
    dubblylinkedList dll;
    dll.appendNode('a');
    dll.appendNode('b');
    dll.appendNode('c');
    dll.appendNode('d');
    dll.appendNode('e');
    // dll.appendNode('f');
    // dll.appendNode('g');
    dll.print();
    dll.Rotate(2);
    cout<<"\n";
    dll.print();
    return 0;
}