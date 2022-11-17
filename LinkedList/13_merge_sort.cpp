/* https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1#
   Merge Sort for Linked List


*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

class Solution
{
public:
    void mergeSorting(Node **head)
    {
        //  initiatisinf=g curr as * to head;
        Node *curr = *head;
        // cheking for null condition
        if (curr == NULL || curr->next == NULL)
        {
            return;
        }
        // sending null first and second to middle
        Node *first;
        Node *second;
        middle(curr, &first, &second);

    //    calling fun for first and sec ll
        mergeSorting(&first);
        mergeSorting(&second);
        *head = mergeboth(first, second);
    }

    // final function that merge the linked list after recution
    Node *mergeboth(Node *first, Node *second)
    {
        Node *ans = NULL;

        // if first gets null then return second
        if (!first)
        {
            return second;
        }
        // if second gets null then return first
        if (!second)
        {
            return first;
        }

        // check if data of fist is small then insert it first to list
        if (first->data <= second->data)
        {
            ans = first;
            ans->next = mergeboth(first->next, second);
        }
        // else  second
        else
        {
            ans = second;
            ans->next = mergeboth(first, second->next);
        }
        return ans;
    }

    // finding middle of two Linked List
    void middle(Node *curr, Node **first, Node **second)
    {
        // here we use little diffrent apreoch for finding middle
        //  that means check null condition for fast pointer every time of its incrementation 

        Node *slow = curr;
        Node *fast = curr->next;
        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *first = curr;
        *second = slow->next;
        slow->next = NULL;
    }
    // main function that calls above functions
    Node *mergeSort(Node *head)
    {
        // passing head by address to update it
        mergeSorting(&head);
        return head;
    }
};

int main()
{

    return 0;
}