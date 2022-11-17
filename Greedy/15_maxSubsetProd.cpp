// Maximum product subset of an array
// Article

/*
here in this problem what we have do is return maximum product of subsets of array

so what we do is in brute force or naive aprrroch find al the subsets of array and then return maximum product

now while thinking like greedy there is much much possibity that evry max can be peoduct of all the elemnet of arr
that meanse all the time whole array can be contibute of max product 

but there are certain cases in que we have negative numbers also and zero also present 
so probelm can be slove in this three cases

1.if there are even number of negative numbers in problem
2. odd number of negatives
single zero case can be handdle
3. but all number are zero and only single gegative number is present then maximum of that negative and zero is zero
so we have to return zere 
as in problem said that find maximum sum of subset of array



couunt neg nums
count zero
count 
*/


#include<bits/stdc++.h>
using namespace std;

int maxSubsetProd(int arr [],int n){
    int countZeros = 0;
    int countNegs  = 0;
    int maxProd = 1;
    int maxNeg = INT_MIN; 
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            countZeros++;
            continue;
        }
        if(arr[i]<0){
            countNegs++;
            maxNeg = max(maxNeg, arr[i]);
        }
        maxProd=maxProd*arr[i];
    }
    if(countZeros==n) return 0;


    // this if is very important comment the code and check the output
    if(countNegs%2){
        // edge case of single negative number and all zeros
        if(countNegs==1 && countZeros > 0 && countNegs + countZeros == n) return 0;

        // this is main step for conveting neg to possitive
       maxProd/=maxNeg;
    }
    return maxProd;
}

int main(){
int arr[]={  -1, 0, 0, 0, 2  };
int n = sizeof(arr)/sizeof(arr[0]);
cout<<maxSubsetProd(arr,n);
    return 0;
}