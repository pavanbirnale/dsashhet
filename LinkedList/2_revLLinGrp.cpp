#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e9 + 7;
struct Node
{
    int data;
    struct Node *next;
};
class solution
{
    struct Node * revGrpWise(struct Node* head,int k){
    struct Node *curr,*next,*prev;
    curr=head;
    prev=NULL;
    int c=0;
    while(curr!=NULL and c<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        c++;
    }
    if(next!=NULL){
        head->next=revGrpWise(next,k);
    }
    return prev;
    }
};
int main()
{

    return 0;
}