// Greedy Algorithm to find Minimum number of Coins
// Choose and Swap

/*
In sheet another problem is given and another probles link is attached
 */

/*
here we have to give lexicographically smallest string if possible
for that what we have to do is check chrecters one by one and if its is greater than next then replace them
*/

#include<bits/stdc++.h>
using namespace std;

string chooseNswap(string a){
int n= a.size();
set<char> s;
for(int i=0;i<n;i++){
    s.insert(a[i]);
}
for(int i=0;i<n;i++){
    s.erase(a[i]);
    char ch = *s.begin();
    if(a[i]>ch){
        char ch2 =a[i];
        for(int j=0;j<n;j++){
            if(a[j]==ch) a[j]=ch2;
            else if(a[j]==ch2) a[j]=ch;
        }
        break;
    }
}
    return a;
}
int main(){
    cout<<chooseNswap("ccad");
  return 0;
}