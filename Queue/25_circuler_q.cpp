/*
Notes:
1.enQueue: there are four cases for enqueue an element  in c_queue
    a). check for full condition
        here is also two separe conditions:
        i).direct check if front and rear are equal to -1;
        ii). and rear = (front - 1) % total  size;
    b). check for 1st element in queue then set front and rear to 0 and rear ++
    c). if rear is at lastt position and front is not at 0th position then set rear to 0 ====> these is C_Queue condition
    d)  incress rear pinter only
2.DeQueue : here is also fpor conditions:
    a.for empty condition
    b.both front and rear are pointing to same possition
    c.front pointiong to last position
    d. incress front++;
*/

#include<bits/stdc++.h>
using namespace std;

class C_Queue{

    int front=-1;
    int rear=-1;
    int size=5;
    int Arr[5];
public:
 void enQueue(int val){
     if(isFull()){
         cout<<"Circuler Queue is Full"<<"\n";
     }
     else if(front==-1){
         rear=front=0;
         Arr[front]=val;
     }
     else if(rear== size-1 && front != 0 ){
         rear=0;
         Arr[rear]=val;
     }
     else{
         rear++;
         Arr[rear]=val;
     }
 }
 int deQueue(){
     if(isEmpty()){
         cout<<"Circuler Queue is Empty"<<"\n";
         return -1;
     }
     int num=Arr[front];
     Arr[front]=-1;
     if(front==rear){
         front=rear=-1;
     }
     else if(front==size-1){
         front=0;
     }
     else{
         front++;
     }
     return num;
 }
 bool isEmpty(){
     if(front==-1) return true;
     return false;
 }
 bool isFull(){
     if(front==0 and rear==size-1 || rear==(front-1)%(size-1))return true;
     return false;
 }
 void Display(){
     for(int i=0;i<size;i++){
         cout<<Arr[i]<<" ";
     }
 }
};
           
int main(){
   C_Queue C_Queue ;  
         C_Queue.enQueue(1); 
         C_Queue.enQueue(2); 
         C_Queue.enQueue(3); 
         C_Queue.deQueue(); 
         C_Queue.deQueue(); 
         C_Queue.deQueue(); 
         C_Queue.deQueue(); 
         C_Queue.deQueue();  
         C_Queue.Display(); 
  return 0;
}