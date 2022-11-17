// Find median in a stream
/*
pepcoading
Algo: 
1. use to heaps min heap and max heap 

what we have to do is to insert data into heaps and return median;
we have three functions ;
first to insert numin heap
second balance heaps
third return median

while inserting num we have to mentain certain condithions 
before that we have two heap left side max heap return maximun elem and right side min heap return min elem
now,
1. if num is greater than right side min heap.top and minheap right side size is >0 push in right
else in left and
check if its size gap is 2 then balce them


2. in balance whose size is more then push its top toanother

3.get median return median
whose size is more that will be median
 and is size is smae then return maxheap.top()+minheap.top()/2
*/

#include<bits/stdc++.h>
using namespace std;

class median{
    public:
    priority_queue<int> maxheap; //right
    priority_queue<int,vector<int>,greater<int>> minheap; //left

    void insertToHeaps(int x){
        // every tim epush intom max heap only this if condin get machen then only push into minheap 
        if(minheap.size()>0  and minheap.top()<x){
            minheap.push(x);
        }
        else{
            maxheap.push(x);
        }
        balanceHeaps();
    }

    void balanceHeaps(){
        // remove from one and push in another
        if(maxheap.size()-minheap.size()==2){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if(minheap.size()-maxheap.size()==2){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }

    int getmedian(){
        // whose size is more that will be median
        if(minheap.size()>maxheap.size()){
            return minheap.top();
        }
        else if(minheap.size()<maxheap.size()){
            return maxheap.top();
        }
        else{
            return (minheap.top()+maxheap.top())/2;
        }
    }
};
int main(){
  median m1;
  int arr[]={5,10,15};
  for(int i=0;i<3;i++){
  m1.insertToHeaps(arr[i]);
  cout<<m1.getmedian()<<" ";
  }
  return 0;
}