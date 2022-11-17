 
 
#include<bits/stdc++.h>
using namespace std;
           
void f(){
    int arr[5];
    // vector<int> arr;
    for(int i=0;i<5;i++){
        arr[i]=i;
    }

    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
}
           
int main(){
      f();
  return 0;
}
 
long long int N = 1e7;
vector<bool> Sieve(int n){
vector<bool> prime(n+1,1);
for (int p = 2; p * p <= n; p++)
{
     if (prime[p] == true) 
     for (int i = p * p; i <= n; i += p) prime[i] = false;
}
return prime;
// for (int p = 2; p <= n; p++)
// if (prime[p])
// cout << p << 
}