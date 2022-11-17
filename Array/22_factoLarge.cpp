// Factorials of large numbers
// problem solved in revision of 2-2-22

 
#include <bits/stdc++.h>
using namespace std;
                     
#define en "\n"
#define vi vector<long long>
#define vii vector<vector<long long>>
#define vll vector<ll>
#define ll long long
#define pii pair<long long, long long>
#define FAST                          \
   ios_base::sync_with_stdio(false); \
   cin.tie(NULL);
  
  
vector<int> factorial(int n)
{
    vector<int>ans(1,1);
    int fact = 1;
    int carry =0;
    int j;
    for(int i=1;i<=n;i++){
        for(j=0;j<ans.size();j++){
            int prod = ans[j]*i;
            ans[j] = (prod%10);
            ans[j]+=carry;
            carry = prod/10;
        }
        if(carry > 0 && j==ans.size() && i!=n){
            ans.push_back(carry);
            carry = 0;
        }
    }
       int temp = ans[ans.size()-1]%10;
       int last = ans[ans.size()-1]/10;
       ans[ans.size()-1] = temp;
       ans.push_back(last+carry);
       return ans; 
}
//   n*fact(n-1)
// 5! = 5*4*3*2*1
int main(){
  
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
FAST;
factorial(10);

    return 0;
}