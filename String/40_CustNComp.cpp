// Function to find Number of customers who could not get a computer
// https://www.geeksforgeeks.org/function-to-find-number-of-customers-who-could-not-get-a-computer/

#include<bits/stdc++.h>
using namespace std;
#define MAX_CHAR 26
int runCustomerSimulation(int n,string cust){
    // occupid counts total number of ocupir]ed comps
    int occupied=0;
    // remaining custmers that non get computer
    int remaining=0;
    char seen[26]={0};
   for(int i=0;i<cust.length();i++){
       int cc=cust[i]-'A';
    //    if custmer comes first time then these if block exicute
       if(seen[cc]==0){
           seen[cc]=1;
        //    if computer are remaining ten give it to custmer
           if(occupied<n){
           occupied++;
           seen[cc]=2;
           }
           else{
               remaining++;
           }
       }
       else{
        //    if custer leave the lab then handle condition
           if(seen[cc]==2){
               occupied--;
           }
           seen[cc]=0;
       }
   }
   return remaining;
}
           
int main(){
      cout << runCustomerSimulation(2, "ABBAJJKZKZ") << endl;
    cout << runCustomerSimulation(3, "GACCBDDBAGEE") << endl;
    cout << runCustomerSimulation(3, "GACCBGDDBAEE") << endl;
    cout << runCustomerSimulation(1, "ABCBCA") << endl;
    cout << runCustomerSimulation(1, "ABCBCADEED") << endl;
  return 0;
}