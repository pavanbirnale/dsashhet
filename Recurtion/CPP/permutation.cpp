#include<bits/stdc++.h>
using namespace std;

void permutation(vector<int> boxes , int currItems,int totalItems){

        if(currItems>totalItems){
            for(int i=0;i<4;i++){
                if(boxes[i]==0){
                    cout<<" -- ";
                }
                else{
                    cout<<" B"<<boxes[i]<<" ";
                }
            }
            cout<<"\n";
            return;
        }

    for(int i=0;i<boxes.size();i++){
        if(boxes[i]==0){
            boxes[i]= currItems;
            permutation(boxes,currItems+1,totalItems);
            boxes[i]=0;
        }
    }
}

int main(){
 vector<int> boxes(4,0);
  permutation(boxes,1,2);
  return 0;
}

// this are the 12 permutuions to add 2 diffent balls in 4 boxes
/*
 B1  B2  --  -- 
 B1  --  B2  -- 
 B1  --  --  B2 
 B2  B1  --  -- 
 --  B1  B2  -- 
 --  B1  --  B2 
 B2  --  B1  -- 
 --  B2  B1  -- 
 --  --  B1  B2 
 B2  --  --  B1 
 --  B2  --  B1 
 --  --  B2  B1
*/