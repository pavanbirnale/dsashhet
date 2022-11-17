// Implement a Maxheap/MinHeap using arrays and recursion.
// Heap
#include<bits/stdc++.h>
using namespace std;

class Heap{
public:

void InsertToHeap(vector<int> &heap,int x){
heap.push_back(x);
int n=heap.size();
int i=n-1;

while(i!=0 and heap[i]>heap[i/2]){
    swap(heap[i],heap[i/2]);
    i=i/2;
}

}
void DeleteFromHeap(vector<int> &heap,int size){
   heap[0]=INT_MIN;
   swap(heap[0],heap[size-1]);
    int i=size-1;
// do hepification
}
};

int main(){
    Heap h;
    vector<int>heap;
    h.InsertToHeap(heap,3);
    h.InsertToHeap(heap,2);
    h.InsertToHeap(heap,100);
    h.InsertToHeap(heap,15);
    h.InsertToHeap(heap,5);
    h.InsertToHeap(heap,4);
    h.InsertToHeap(heap,45);
    int n=heap.size();
    h.DeleteFromHeap(heap,n);
    for(int i=0;i<n;i++){
        cout<<heap[i]<<" ";
    }
  return 0;
}