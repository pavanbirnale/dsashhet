// Write a program to Detect loop in a linked list.
// https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1#

// Two Apreoches
// 1st TC O(N) SC O(N)
// 2nd TC O(N) SC O(1)

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node{
    int data;
    struct Node *next;
};
class solution{
    // O(N) space
    bool detLop(struct Node * head){
        if(!head) return head;
        unordered_map<Node*,int> mp;
        while(!head){
            if(!mp[head]){
                mp[head]=1;
                head=head->next;
            }
            else{
                return true;
            }
        }
        return false;
    }
    // O(1) Space 
    // Rare and Tortoice Stratgy
    bool detLop2(struct Node* head){
        Node* lo=head;
        Node* hi=head;
        while(!hi and !hi->next){
            lo=lo->next;
            hi=hi->next->next;
            if(hi==lo) return true;
        }
        return false;
    }
};
           
int main(){
          
  return 0;
}