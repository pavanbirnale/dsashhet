#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *a[])
{
    string lt,tt;
    getline(cin, lt);
    getline(cin, tt);

    int lth,ltm,tth,ttm;
    lth = stoi(lt.substr(0,2));
    ltm = stoi(lt.substr(3));
    tth = stoi(tt.substr(0,2));
    ttm = stoi(tt.substr(3));

    int mins = ltm + ttm;
    int carry = mins / 60;
    mins = mins % 60;
    int hrs = lth + tth;
    hrs%=24;
    hrs+=carry;

    if(hrs==24 || hrs==0) cout<<"00"<<" ";
    else if(to_string(hrs).size() == 1) cout<<"0"<<hrs<<" ";
    else cout<<hrs<<" ";

    if(mins==0) cout<<"00"<<endl;
    else if(to_string(mins).size() == 1) cout<<"0"<<mins<<endl;
    else cout<<mins<<endl;
  return 0;
}
