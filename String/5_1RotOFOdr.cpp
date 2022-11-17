// Write a Code to check whether one string is a rotation of another
// https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/
#include <bits/stdc++.h>
using namespace std;

bool isRotofOther(string s1, string s2)
{
  if (s1.length() != s2.length())
    return 0;
  string s = s1 + s1;
  if(s.find(s2)!= string::npos){
    return 1;
  }
  return 0;
}
int main()
{
  string str1 = "ABC";
  string str2 = "CAB";
  cout<<isRotofOther(str1, str2);
   return 0;
}