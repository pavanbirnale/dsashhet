// IMP
// https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1#
// Merge K sorted linked lists

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

class Solution{
  public:
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
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
          int i=0;
          int last=K-1;
          int j;
          while(last!=0){
              i=0;
              j=last;
              while(i<j){
                  arr[i]=mergeboth(arr[i],arr[j]);
                  i++;
                  j--;
                //   creoss i and j then stop
                  if(i>=j){
                      last=j;
                  }
              }
          
          }
              return arr[0];
          
    }
};
/*
approch same like these
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5
1 2 3
1 2
1
*/
int main(){
          
  return 0;
}