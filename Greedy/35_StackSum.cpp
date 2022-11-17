// Find maximum sum possible equal sum of three stacks

/*
Here what we have to do is remove one by one elemnt from that stack whose sum is greater among them 
then find the maximum equal sum of all the three stack
*/
#include<bits/stdc++.h>
using namespace std;

           
int main(){
  int n1,n2,n3;
  cin>>n1>>n2>>n3;
  
  int arr1[n1];
  int arr2[n2];
  int arr3[n3];

  for(int i=0;i<n1;i++){ cin>>arr1[i];}
  for(int i=0;i<n2;i++){ cin>>arr2[i];}
  for(int i=0;i<n3;i++){ cin>>arr3[i];}

  int sum1=0,sum2=0,sum3=0;
  for(int i=0;i<n1;i++){ sum1+=arr1[i];}
  for(int i=0;i<n2;i++){ sum2+=arr2[i];}
  for(int i=0;i<n3;i++){ sum3+=arr3[i];}

int top1=0,top2=0,top3=0;

while(true){
    if(top1==n1 or top2==n2 or top3==n3){
        cout<<"0";
        break;
    }
    if(sum1==sum2 and sum2==sum3){
        cout<<sum1;
        break;
    }

    if(sum1>sum2 and sum1>sum3){
        sum1-=arr1[top1++];
    }
    else if(sum2>sum1 and sum2>sum3){
        sum2-=arr2[top2++];
    }
    else{
        sum3-=arr3[top3++];
    }
}
  return 0;
}
