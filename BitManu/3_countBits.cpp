// Count the number of bits that are required to flip A to B

#include<bits/stdc++.h>
using namespace std;

int bitCount(int A,int B){

    int Xor = A^B;
    int c = 0;
    while(Xor){
        Xor = Xor &(Xor - 1);
        c++;
    }
    return c;
}

int main(){
       
  return 0;
}