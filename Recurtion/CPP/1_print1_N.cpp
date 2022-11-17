#include<bits/stdc++.h>
using namespace std;

// 1. Write a recursive function to print numbers from 1 to n
void print1toN(int i,int n){
if(i>n) return;
cout<<i<<'\n';
print1toN(i+1,n);
}

// 2. Write a recursive function to print number from n to 1;
void printNto1(int n){
if(n<0) return;
cout<<n<<'\n';
printNto1(n-1);
}
           
int main(){
  int n=10;
//   print1toN(0,n);
printNto1(n);
  return 0;
}