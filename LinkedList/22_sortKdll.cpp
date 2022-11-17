// Sort a “k”sorted Doubly Linked list.[Very IMP]
// https://www.geeksforgeeks.org/sort-k-sorted-doubly-linked-list/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// comarator function for createing min heap;
struct compare
{
    bool operator()(Node *first, Node *second)
    {
        return first->data > second->data;
    }
};


Node *SortKLinkedList(Node *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;

// creating pq of size k and pushing first k elment to it
    priority_queue<Node *, vector<Node *>, compare> pq;

    struct Node *newnode = NULL, *curr;
    for (int i = 0; head!=NULL && i <= k; i++)
    {
        pq.push(head);
        head = head->next;
    }


// then we pop top of pq one by one and push next node in pq
    while (!pq.empty())
    {
        if (newnode == NULL)
        {
            newnode = pq.top();
            newnode->prev = NULL;
            curr = newnode;
        }
        else
        {
            curr->next = pq.top();
            pq.top()->prev = curr;
            curr = pq.top();
        }
        pq.pop();

// here is pushing new node
        if (head != NULL)
        {
            pq.push(head);
            head = head->next;
        }
    }
    curr->next = NULL;
    return newnode;
}

int main()
{
    return 0;
}
