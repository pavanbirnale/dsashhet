// Maximize array sum after K negations

/*
in this problem we have to  get maximum summ of all the elment by converting 
neg elemt to possitive and possitive elemnt to negative by k times

so what we do calulate numof neg numbers in array 
if theay are greter than k then simly convert the first k neg to possitive and calculate sum

but if negnums are less then 
first convert the all the negative nums to possive 
then now we have k-negnums ks are remaing


now here is logic comes now play with first lesser number on converting it to possitive nad negative to dectress k

if k-neg num % 2==0 then final array hass all elemnt +ve

if k-neg %2 ==1 thren first array elem is -ve 
acording to that calculate ans;
*/
#include<bits/stdc++.h>
using namespace std;

long long int maximizeSum(long long int a[], int n, int k)
    {
    sort(a,a+n);
    int negCount=0;
    for(int i=0;i<n;i++){
        if(a[i]<0) negCount++;
    }
    long long int sum=0;
    
    if(negCount>=k){
        for(int i=0;i<k;i++){
            a[i]= -a[i];
        }
        for(int i=0;i<n;i++){
            sum+= a[i];
        }
    }
    else{
        for(int i=0;i<negCount;i++){
            a[i]= -a[i];
        }
        sort(a,a+n);
        int remain = k-negCount;
        if(remain%2==0){
             for(int i=0;i<n;i++){
            sum+= a[i];
        }
        }
        else{
            a[0]= -a[0];
            for(int i=0;i<n;i++){
            sum+= a[i];
        }
        }
    }
    return sum;
    }
           
int main(){
          
  return 0;
}